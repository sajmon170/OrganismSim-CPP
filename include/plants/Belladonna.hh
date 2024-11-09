#include "Plant.hh"

struct Belladonna : public Plant {
	Belladonna(Vector2 pos, World& world)
		: Plant("🫐", "Belladonna", 99, pos, world) {}

	Belladonna* createChild() const final override;
	CollisionData collision(Organism*) final override;

	~Belladonna() override = default;
};
