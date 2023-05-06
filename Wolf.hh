#include "Animal.hh"

struct Wolf : public Animal {
	Wolf(Vector2 pos, World& world)
		: Animal("🐺", "Wolf", 9, 5, pos, world) {}

	Wolf* createChild() const final override;

	~Wolf() override = default;
};
