#include "CursesApp.hh"
#include <clocale>

CursesApp::CursesApp() {
	std::setlocale(LC_ALL, "");
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, true);
}

CursesApp::~CursesApp() {
	destroy();
	endwin();
}

void CursesApp::addWindow(std::string identifier, Window* window) {
	screen.insert(std::pair<std::string, Window*>(identifier, window));
}

void CursesApp::addWindow(Window* window) {
	addWindow(window->getTitle(), window);
}

Window& CursesApp::get(std::string identifier) {
	return *screen[identifier];
}

void CursesApp::display() {
	for (auto& [_, window]: screen) {
		window->display();
		window->clear();
	}
}

void CursesApp::readjust() {
	napms(1000/30);
	for (auto& [_, window]: screen) {
		window->readjust();
	}
}

void CursesApp::clear() {
	erase();
	refresh();
}

void CursesApp::destroy() {
	for (auto&& [identifier, window] : screen)
		delete window;
	screen.clear();
}
