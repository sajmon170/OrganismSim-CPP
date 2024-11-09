#include "Simulator.hh"

auto main() -> int {
	Simulator program = Simulator::Builder()
		.setInitialPopulation(100)
		.setMaxPopulation(1000)
		.setSpawnRadius(25)
		.build();
	
	program.run();
}
