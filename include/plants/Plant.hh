#pragma once

#include "Organism.hh"
#include "World.hh"
#include <string>

class Plant : public Organism {
protected:
	void offspring() const;
	
public:
	Plant(std::string display,
	      std::string name,
	      int strength,
	      Vector2 position,
	      World& world)
		: Organism(display, name, strength, 0, position, world) {};
	virtual void action() override;
	virtual CollisionData collision(Organism*) override;
};
