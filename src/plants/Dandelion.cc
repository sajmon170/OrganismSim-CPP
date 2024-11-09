#include "Dandelion.hh"

Dandelion* Dandelion::createChild() const {
	return new Dandelion(randomPosNear(), world);
}

void Dandelion::action() {
	if (Math::chance(0.6)) {
		die();
	}
	else {
		for (int i=0; i<3; i++)
			offspring();
	}
}
