#include "OrganismFactory.hh"
#include "Animals.hh"
#include "Plants.hh"

#include <cctype>

std::vector<std::string> OrganismFactory::ALL_ORGANISMS = {
	/*Animals*/    /*Plants*/
	"Antelope",    "Belladonna",
	"Fox",         "Dandelion",
	"Sheep",       "Grass",
	"Turtle",      "Guarana",
	"Wolf",        "Sosnowsky"
};

Organism* OrganismFactory::spawn(std::string name, Vector2 position) const {
	Math::map(name, tolower);

	if (name == "grass")
		return new Grass(position, world);
	if (name == "guarana")
		return new Guarana(position, world);
	if (name == "dandelion")
		return new Dandelion(position, world);
	if (name == "belladonna")
		return new Belladonna(position, world);
	if (name == "sosnowsky")
		return new Sosnowsky(position, world);
	if (name == "wolf")
		return new Wolf(position, world);
	if (name == "sheep")
		return new Sheep(position, world);
	if (name == "fox")
		return new Fox(position, world);
	if (name == "turtle")
		return new Turtle(position, world);
	if (name == "antelope")
		return new Antelope(position, world);
	if (name == "human")
		return new Human(position, world);

	return nullptr;
}
