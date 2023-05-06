#include "Sheep.hh"

Sheep* Sheep::createChild() const {
	return new Sheep(randomPosNear(), world);
}
