#include "Animal.hh"
#include <random>
#include <ctime>
#include <algorithm>

void Animal::move() {
	move(Math::pickRandom(nearPos()));
}

void Animal::move(Vector2 const& new_pos) {
	Vector2 old_pos = getPos();
	if (world.getField(new_pos).has_value()) {
		CollisionData data = (*world.getField(new_pos))->collision(this);
		if (data.didEvade()) {
			raiseEvent("was evaded.");
			return;
		}
		if (data.didPush()) {
			raiseEvent("was pushed away.");
			move(randomPosNear());
			return;
		}
	}
	if (isAlive()) {
		world.eraseField(old_pos);
		setPos(new_pos);
		world.setField(getPos(), this);
	}
}

void Animal::action() {
	move();
}

CollisionData Animal::collision(Organism* organism) {
	CollisionData status = tryReproduce(organism);
	if (status.didReproduce())
		return status;

	if (this->getStrength() > organism->getStrength()) {
		organism->die();
		raiseEvent(std::string("killed ") + organism->getDisplay());
	}
	else {
		raiseEvent(std::string("was killed by") + organism->getDisplay());
		this->die();
	}

	return CollisionData::Builder()
		.setHappened()
		.build();
}

CollisionData Animal::tryReproduce(Organism* organism) const {
	if (typeid(*this) != typeid(*organism)) {
		return CollisionData::Builder()
			.setHappened()
			.build();
	}

	Animal* parent = static_cast<Animal*>(organism);
	
	std::vector<Vector2> pos = this->nearPos();
	std::vector<Vector2> pos2 = parent->nearPos();
	pos.insert(pos.end(), pos2.begin(), pos2.end());

	Math::remove(pos, this->getPos());
	Math::remove(pos, parent->getPos());

	world.queue(createChild(), Math::pickRandom(pos));

	return CollisionData::Builder()
		.setHappened()
		.setReproduced()
		.build();
}
