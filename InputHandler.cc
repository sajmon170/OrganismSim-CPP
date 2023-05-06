#include "Simulator.hh"
#include "Window.hh"

int const Simulator::InputHandler::KEY_DEFAULT = 0;

Simulator::InputHandler::InputHandler(Simulator& sim)
	: simulator(sim) {
	bindings = {
		{KEY_DEFAULT, doNothing},
		{KEY_RESIZE, resize},
		{KEY_F(9), save},
		{KEY_F(10), load},
		{KEY_UP, cameraUp},
		{KEY_DOWN, cameraDown},
		{KEY_LEFT, cameraLeft},
		{KEY_RIGHT, cameraRight},
		{'\n', activateAbility},
		{'w', goUp},
		{'W', goUp},
		{'a', goLeft},
		{'A', goLeft},
		{'s', goDown},
		{'S', goDown},
		{'d', goRight},
		{'D', goRight},
		{' ', advance},
		{'q', quit},
		{'Q', quit}
	};
}


void Simulator::InputHandler::process(int input) {
	if (bindings.count(input) > 0)
		bindings.at(input)(simulator);
	else
		bindings.at(KEY_DEFAULT)(simulator);
}

void Simulator::InputHandler::doNothing(Simulator&) {
	return;
}

void Simulator::InputHandler::resize(Simulator& simulator) {
	simulator.program.destroy();
	simulator.initializeWindow();
}

void Simulator::InputHandler::save(Simulator& simulator) {
	simulator.saveState();
}

void Simulator::InputHandler::load(Simulator& simulator) {
	simulator.loadState();
}

void Simulator::InputHandler::cameraUp(Simulator& simulator) {
	simulator.camera.setY(simulator.camera.getY() + 1);
}

void Simulator::InputHandler::cameraDown(Simulator& simulator) {
	simulator.camera.setY(simulator.camera.getY() - 1);
}

void Simulator::InputHandler::cameraLeft(Simulator& simulator) {
	simulator.camera.setX(simulator.camera.getX() + 1);
}

void Simulator::InputHandler::cameraRight(Simulator& simulator) {
	simulator.camera.setX(simulator.camera.getX() - 1);
}

void Simulator::InputHandler::activateAbility(Simulator& simulator) {
	if (simulator.human != nullptr)
		simulator.human->setAbility();
	simulator.world.advance();
}

void Simulator::InputHandler::goUp(Simulator& simulator) {
	if (simulator.human != nullptr)
		simulator.human->moveUp();
	simulator.world.advance();
}

void Simulator::InputHandler::goDown(Simulator& simulator) {
	if (simulator.human != nullptr)
		simulator.human->moveDown();
	simulator.world.advance();
}

void Simulator::InputHandler::goLeft(Simulator& simulator) {
	if (simulator.human != nullptr)
		simulator.human->moveLeft();
	simulator.world.advance();
}

void Simulator::InputHandler::goRight(Simulator& simulator) {
	if (simulator.human != nullptr)
		simulator.human->moveRight();
	simulator.world.advance();
}

void Simulator::InputHandler::advance(Simulator& simulator) {
	simulator.world.advance();
}

void Simulator::InputHandler::quit(Simulator& simulator) {
	simulator.setFinished();
}
