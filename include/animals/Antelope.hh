#include "Animal.hh"

struct Antelope : public Animal {
	Antelope(Vector2 pos, World& world)
		: Animal("🦌", "Antelope", 4, 4, pos, world) {}

	Antelope* createChild() const final override;
	void action() final override;
	CollisionData collision(Organism*) final override;
	~Antelope() override = default;
};
