#include "Simulator.hh"

auto main() -> int {
	Simulator program = Simulator::Builder()
		.setInitialPopulation(50)
		.setMaxPopulation(1000)
		.setSpawnRadius(25)
		.build();
	
	program.run();
}
