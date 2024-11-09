#include "Sosnowsky.hh"

Sosnowsky* Sosnowsky::createChild() const {
	return new Sosnowsky(randomPosNear(), world);
}

void Sosnowsky::action() {
	for (Organism* organism: near())
		organism->die();
}
