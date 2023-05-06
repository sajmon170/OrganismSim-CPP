#include "Animal.hh"

struct Sheep : public Animal {
Sheep(Vector2 pos, World& world)
	: Animal("🐑", "Sheep", 4, 4, pos, world) {}

	Sheep* createChild() const final override;

	~Sheep() override = default;
};
