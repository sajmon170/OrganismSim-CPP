#pragma once

#include "Math.hh"
#include "Vector2.hh"

#include <list>
#include <vector>
#include <unordered_map>
#include <optional>

class Organism;

class World {
	std::list<Organism*> organisms;
	std::list<Organism*> next;
	std::unordered_map<Vector2, Organism*> field;
	std::vector<std::string> events;
	int max_population;

protected:
	void kill_oldest();
	void mergeGenerations();
	
public:
	World(int max_population)
		: max_population(max_population) {}
	
	std::optional<Organism*> getField(Vector2);
	inline std::unordered_map<Vector2, Organism*> const& getFields() const {
		return field;
	}
	void setField(Vector2, Organism*);
	
	void advance();
	void queue(Organism*, Vector2 pos);

	void eraseField(Vector2);
	void addEvent(std::string const&);
	inline void clearEvents() {
		events.clear();
	}
	std::vector<std::string>& getEvents();

	void clear();
	~World();
};
