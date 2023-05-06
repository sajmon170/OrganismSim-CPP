#include "Animal.hh"

struct Fox : public Animal {
	Fox(Vector2 pos, World& world)
		: Animal("🦊", "Fox", 3, 7, pos, world) {}

	Fox* createChild() const final override;
	void action() final override;

	~Fox() override = default;
};
