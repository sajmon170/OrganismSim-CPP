#include "Animal.hh"

class Human : public Animal {
	Vector2 change = Vector2{0, 0};
	int timer = 0;
	int cooldown = 0;
	
public:
	Human(Vector2 pos, World& world)
		: Animal("😎", "Human", 5, 4, pos, world) {}

	Human* createChild() const final override;

	void setAbility();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void action() override;
	CollisionData collision(Organism*) override;

	~Human() override = default;
	
};
