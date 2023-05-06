#include "Simulator.hh"
#include "Math.hh"
#include "Vector2.hh"

#include <fstream>

void Simulator::initializeWindow() {
	erase();
	refresh();
	// Screen dimensions
	int max_x = getmaxx(stdscr);
	int max_y = getmaxy(stdscr);

	// Constraints
	int x_div = 0.3 * getmaxx(stdscr);
	int y_div = getmaxy(stdscr) - 2;
	
	program.addWindows({
		new ItemListWindow("Info", y_div, x_div, 0, 1),
		new GridWindow("Simulation", y_div, max_x - x_div-3, 0, x_div + 2),
		new StatusBarWindow("Status", max_x, y_div+1, 1),
		new InputListenerWindow("Input")
	});

	auto& grid = static_cast<GridWindow&>(program.get("Simulation"));

	camera = Vector2{
		grid.getContentSizeX(),
		grid.getContentSizeY(),
	} / 2;

	program.get("Status").addItems({"<q> Quit", "<F9> Save", "<F10> Load"});
	program.get("Input").enableListening();
}

Simulator::Simulator(int initial_population, int max_population, int radius)
	: world(max_population), spawner(world), initial(initial_population) {
	finished = false;
	
	auto& organism_set = OrganismFactory::ALL_ORGANISMS;
	human = new Human(Vector2{0, 0}, world);
	world.queue(human, human->getPos());
	
	for (int i=0; i<initial_population; i++) {
		Vector2 position = Math::randomPos(radius);
		Organism* organism = spawner.spawn(Math::pickRandom(organism_set),
		                                   position);
		world.queue(organism, position);
	}
	
	initializeWindow();
}

void Simulator::saveState() {
	std::ofstream file;
	file.exceptions(std::ofstream::failbit);
		
	try {
		file.open("save.txt");
	}
	catch (std::ofstream::failure const& ex) {
		world.addEvent("Could not save file.");
		return;
	}

	for (auto& [pos, name]: world.getFields())
			file << pos.getX() << " " << pos.getY() << " " << name->getName() << "\n";
	
	file.close();

	world.addEvent("Saved state.\n");
}

void Simulator::loadState() {
	std::ifstream file("save.txt");

	if (file.fail()) {
		world.addEvent("Could not load state.");
		return;
	}
	
	world.clear();

	int x, y;
	std::string name;
	while (file >> x >> y >> name) {
		Vector2 position = Vector2(x, y);
		if (name == "Human") {
			human = new Human(position, world);
			world.queue(human, position);
		}
		else {
			Organism* organism = spawner.spawn(name, Vector2(x, y));
			world.queue(organism, position);
		}
		
	}
	
	file.close();

	world.advance();
	world.addEvent("State loaded.\n");
}

void Simulator::run() {
	InputHandler handler(*this);
	
	int input = 0;
	world.advance();
	
	while (isRunning()) {
		auto& grid = static_cast<GridWindow&>(program.get("Simulation"));
		auto& info = static_cast<ItemListWindow&>(program.get("Info"));

		for (int y=0; y<grid.getContentSizeY(); y++) {
			for (int x=0; x<grid.getContentSizeX(); x++) {
				auto pos = Vector2(x, y);
				auto field = world.getField(pos - camera);
				if (field.has_value())
					grid.addItem(pos, (*field)->getDisplay());
			}
		}

		for (auto& event: world.getEvents())
			info.addItem(event.c_str());

		program.display();

		world.clearEvents();

		input = program.get("Input").getChar();
		handler.process(input);
	}
	while (isRunning());
}

Simulator::Builder& Simulator::Builder::setInitialPopulation(int population) {
	initial_population = population;
	return *this;
}

Simulator::Builder& Simulator::Builder::setMaxPopulation(int population) {
	max_population = population;
	return *this;
}

Simulator::Builder& Simulator::Builder::setSpawnRadius(int r) {
	radius = r;
	return *this;
}

Simulator Simulator::Builder::build() {
	return Simulator(initial_population, max_population, radius);
}
