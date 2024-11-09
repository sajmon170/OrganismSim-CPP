#include "Plant.hh"

struct Guarana : public Plant {
	Guarana(Vector2 pos, World& world)
		: Plant("🫒", "Guarana", 0, pos, world) {}

	Guarana* createChild() const final override;
	CollisionData collision(Organism*) final override;

	~Guarana() override = default;
};
