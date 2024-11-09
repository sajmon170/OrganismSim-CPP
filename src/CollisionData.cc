#include "CollisionData.hh"

CollisionData::Builder& CollisionData::Builder::setHappened() {
	collision.did_happen = true;
	return *this;
}

CollisionData::Builder& CollisionData::Builder::setEvaded() {
	collision.did_evade = true;
	return *this;
}

CollisionData::Builder& CollisionData::Builder::setPushed() {
	collision.did_push = true;
	return *this;
}

CollisionData::Builder& CollisionData::Builder::setReproduced() {
	collision.did_reproduce = true;
	return *this;
}

CollisionData CollisionData::Builder::build() {
	return collision;
}
