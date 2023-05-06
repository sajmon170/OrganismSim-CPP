#include "Plant.hh"
#include <random>
#include <ctime>
#include <algorithm>

void Plant::action() {
	if (Math::chance(0.25))
		offspring();
}

CollisionData Plant::collision(Organism* organism) {
	world.addEvent(organism->getDisplay() + std::string(" ate ") + getDisplay());
	die();
	return CollisionData::Builder()
		.setHappened()
		.build();
}

void Plant::offspring() const {
	std::vector<Vector2> pos = nearPos();
	pos.erase(std::remove(pos.begin(), pos.end(), getPos()),
	          pos.end());

	Math::remove(pos, getPos());

	world.queue(createChild(), Math::pickRandom(pos));
}
