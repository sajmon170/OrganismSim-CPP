#pragma once

#include "Math.hh"
#include "CollisionData.hh"

#include <vector>
#include <string>

class World;

class Organism {
	static int count;
	int id;
	const std::string display;
	const std::string name;
	Vector2 pos;
	
protected:
	World& world;
	int strength;
	int initiative;
	bool is_alive;
	void setId();

public:
	Organism(std::string display, std::string name, int strength,
	         int initiative, Vector2 position, World& world)
		: display(display), name(name), strength(strength),
		  initiative(initiative), pos(position), world(world) {
		is_alive = true;
		setId();
	}

	inline char const* getDisplay() const { return display.c_str(); }
	inline char const* getName() const { return name.c_str(); }
	inline int getStrength() const { return strength; }
	inline void addStrength(int amount) { strength += amount; }
	inline int getInitiative() const { return initiative; }
	inline int getBirthday() const { return id; }
	inline bool isAlive() const { return is_alive; }
	inline bool isDead() const { return not is_alive; }
	void die();

	Vector2 getPos() const { return pos; };
	void setPos(Vector2 v) { pos = v; };
	
	std::vector<Vector2> nearPos() const;
	std::vector<Organism*> near() const;
	Vector2 randomPosNear() const;
	void raiseEvent(std::string const&&) const;
	
	bool operator==(Organism const&) const;

	virtual void action() = 0;
	virtual CollisionData collision(Organism*) = 0;
	[[nodiscard("alloc'd Organism child pointer lost.")]]
	virtual Organism* createChild() const = 0;
	virtual ~Organism() {};
};
