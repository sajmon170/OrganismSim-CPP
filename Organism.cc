#include "Organism.hh"
#include "World.hh"

int Organism::count = 0;

void Organism::setId() {
	id = count++;
}

Vector2 Organism::randomPosNear() const {
	return Math::pickRandom(nearPos());
}

void Organism::raiseEvent(std::string const&& event) const {
	world.addEvent(getDisplay() + (" " + event));
}

std::vector<Vector2> Organism::nearPos() const {
	std::vector<int> x_pos = Math::range(pos.getX()-1, pos.getX()+1);
	std::vector<int> y_pos = Math::range(pos.getY()-1, pos.getY()+1);
	std::vector<Vector2> result;
	
	for (auto& x: x_pos)
		for (auto& y: y_pos)
			result.push_back(Vector2{x, y});

	Math::remove(result, pos);
	return result;
}

std::vector<Organism*> Organism::near() const {
	std::vector<Organism*> result;
	for (auto& pos: nearPos()) {
		auto fetch = world.getField(pos);
		if (fetch.has_value() && (*fetch)->isAlive())
			result.push_back(*fetch);
	}

	return result;
}

bool Organism::operator==(Organism const& organism) const {
	return (this->id == organism.id);
}

void Organism::die() {
	is_alive = false;
	world.eraseField(pos);
}
