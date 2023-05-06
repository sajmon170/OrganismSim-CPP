#pragma once

#include "Organism.hh"
#include "Math.hh"

#include <string>

class World;

class OrganismFactory {
	World& world;

public:
	static std::vector<std::string> ALL_ORGANISMS;
	OrganismFactory(World& world)
		: world(world) {}

	[[nodiscard("Spawned organism unused - alloc'd organism pointer lost.")]]
	Organism* spawn(std::string name, Vector2 position) const;
};
