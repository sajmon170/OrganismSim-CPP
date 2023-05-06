#include "Grass.hh"

Grass* Grass::createChild() const {
	return new Grass(randomPosNear(), world);
}
