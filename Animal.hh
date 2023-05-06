#pragma once

#include "Organism.hh"
#include "World.hh"
#include <string>

class Animal : public Organism {
protected:
	CollisionData tryReproduce(Organism*) const;

public:
	Animal(std::string display,
	       std::string name,
	       int strength,
	       int initiative,
	       Vector2 position,
	       World& world)
		: Organism(display, name, strength, initiative, position, world) {};
	void move();
	void move(Vector2 const&);
	virtual void action() override;
	virtual CollisionData collision(Organism*) override;
};
