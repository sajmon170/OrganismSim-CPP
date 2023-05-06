#include "Plant.hh"

struct Sosnowsky : public Plant {
	Sosnowsky(Vector2 pos, World& world)
		: Plant("💀", "Sosnowsky", 10, pos, world) {}

	Sosnowsky* createChild() const final override;
	void action() final override;

	~Sosnowsky() override = default;
};
