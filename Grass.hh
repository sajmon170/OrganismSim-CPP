#include "Plant.hh"

struct Grass : public Plant {
	Grass(Vector2 pos, World& world)
		: Plant("🌱", "Grass", 0, pos, world) {}

	Grass* createChild() const final override;

	~Grass() override = default;
};
