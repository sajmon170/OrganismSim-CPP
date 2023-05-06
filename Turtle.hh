#include "Animal.hh"

struct Turtle : public Animal {
	Turtle(Vector2 pos, World& world)
		: Animal("🐢", "Turtle", 2, 1, pos, world) {}

	Turtle* createChild() const final override;
	void action() final override;
	CollisionData collision(Organism*) final override;
	~Turtle() override = default;
};
