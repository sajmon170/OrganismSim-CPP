#include "Belladonna.hh"

Belladonna* Belladonna::createChild() const {
	return new Belladonna(randomPosNear(), world);
}

CollisionData Belladonna::collision(Organism* organism) {
	organism->die();
	return Plant::collision(organism);
}
