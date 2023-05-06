#pragma once

#include "CursesApp.hh"
#include "OrganismFactory.hh"
#include "Human.hh"
#include "World.hh"
#include "Vector2.hh"

#include <vector>
#include <functional>

class Simulator {
	World world;
	const OrganismFactory spawner;
	const int initial;
	CursesApp program;
	Vector2 camera;
	Human* human;
	bool finished;

protected:
	Simulator(int initial_population, int max_population, int radius);
	void initializeWindow();
	void saveState();
	void loadState();
	
public:
	class InputHandler;
	friend class InputHandler;
	
	class Builder;
	friend class Builder;

	void run();
	
	inline void setFinished() {
		finished = true;
	}

	inline bool isRunning() {
		return !finished;
	}
};

class Simulator::Builder {
	int initial_population = 1;
	int max_population = 1;
	int radius = 1;
	
public:
	Builder() = default;
	Builder& setInitialPopulation(int);
	Builder& setMaxPopulation(int);
	Builder& setSpawnRadius(int);
	Simulator build();
};

class Simulator::InputHandler {
	Simulator& simulator;
	std::unordered_map<int, std::function<void(Simulator&)>> bindings;
	static int const KEY_DEFAULT;

protected:
	static void doNothing(Simulator&);
	static void resize(Simulator&);
	static void save(Simulator&);
	static void load(Simulator&);
	static void cameraUp(Simulator&);
	static void cameraDown(Simulator&);
	static void cameraLeft(Simulator&);
	static void cameraRight(Simulator&);
	static void activateAbility(Simulator&);
	static void goUp(Simulator&);
	static void goDown(Simulator&);
	static void goLeft(Simulator&);
	static void goRight(Simulator&);
	static void advance(Simulator&);
	static void quit(Simulator&);
	
public:
InputHandler(Simulator& sim);
	void process(int input);
};
