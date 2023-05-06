#include "Turtle.hh"

Turtle* Turtle::createChild() const {
	return new Turtle(randomPosNear(), world);
}

void Turtle::action() {
	if (Math::chance(0.25))
		move(randomPosNear());
}

CollisionData Turtle::collision(Organism* organism) {
	CollisionData status = tryReproduce(organism);
	if (status.didReproduce())
		return status;

	if (organism->getStrength() < 5)
		return CollisionData::Builder()
			.setEvaded()
			.build();
	
	die();
	return CollisionData::Builder()
		.setHappened()
		.build();
}
