#pragma once

class CollisionData {
	bool did_happen = false;
	bool did_evade = false;
	bool did_push = false;
	bool did_reproduce = false;
	CollisionData() = default;

public:
	bool didHappen() const { return did_happen; }
	bool didEvade() const { return did_evade; }
	bool didPush() const { return did_push; };
	bool didReproduce() const { return did_reproduce; }

	class Builder;
	friend class CollisionData::Builder;
};

class CollisionData::Builder {
	CollisionData collision;

public:
	Builder() = default;
	CollisionData::Builder& setHappened();
	CollisionData::Builder& setEvaded();
	CollisionData::Builder& setPushed();
	CollisionData::Builder& setReproduced();
	CollisionData build();
};
