#include "Guarana.hh"

Guarana* Guarana::createChild() const {
	return new Guarana(randomPosNear(), world);
}

CollisionData Guarana::collision(Organism* organism) {
	organism->addStrength(3);
	return Plant::collision(organism);
}
