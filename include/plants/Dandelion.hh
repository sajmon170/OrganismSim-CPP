#include "Plant.hh"

struct Dandelion : public Plant {
	Dandelion(Vector2 pos, World& world)
		: Plant("🌼", "Dandelion", 0, pos, world) {}

	Dandelion* createChild() const final override;
	void action() final override;

	~Dandelion() override = default;
};
