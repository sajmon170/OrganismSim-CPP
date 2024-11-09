#include "World.hh"
#include "Organism.hh"

#include <iostream>
#include <algorithm>
#include <curses.h>

void World::kill_oldest() {
	auto index = organisms.begin();
	Organism* oldest = *index;

	for (auto it = organisms.begin(); it != organisms.end(); it++)
		if ((*it)->getBirthday() < oldest->getBirthday()) {
			oldest = *it;
			index = it;
		}

	addEvent((*index)->getDisplay() + std::string(" died of old age."));
	Vector2 pos = oldest->getPos();
	field.erase(pos);
	organisms.erase(index);
	delete oldest;
}

std::optional<Organism*> World::getField(Vector2 pos) {
	try {
		return field.at(pos);
	}
	catch (std::out_of_range exception) {
		return {};
	}
}

void World::mergeGenerations() {	
	for (auto& organism: next) {
		if (getField(organism->getPos()).has_value()) {
			delete organism;
			organism = nullptr;
		}
		else
			setField(organism->getPos(), organism);
	}

	Math::filter(next, [](Organism* organism) {
		return organism == nullptr;
	});
	
	organisms.splice(organisms.end(), next);

	while (organisms.size() > max_population)
		kill_oldest();
	
	organisms.sort([](Organism* a, Organism* b) {
		return a->getInitiative() > b->getInitiative();
	});
}

void World::advance() {
	for (auto& organism: organisms)
		if (organism->isAlive())
			organism->action();
	
	Math::filter(organisms, [](Organism*& organism) {
		bool is_dead = organism->isDead();
		if (is_dead) {
			delete organism;
		}
		return is_dead;
	});

	mergeGenerations();
}

void World::queue(Organism* organism, Vector2 pos) {
	next.push_back(organism);
}

void World::eraseField(Vector2 position) {
	field.erase(position);
}

void World::setField(Vector2 position, Organism* organism) {
	field.insert(std::pair<Vector2, Organism*>(position, organism));
}

void World::addEvent(std::string const& event) {
	events.push_back(event);
}

std::vector<std::string>& World::getEvents() {
	return events;
}

void World::clear() {
	for (auto& organism: organisms)
		delete organism;

	organisms.clear();
	next.clear();
	events.clear();
	field.clear();
}

World::~World() {
	clear();
}
