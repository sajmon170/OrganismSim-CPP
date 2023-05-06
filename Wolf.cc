#include "Wolf.hh"

Wolf* Wolf::createChild() const {
	return new Wolf(randomPosNear(), world);
}
