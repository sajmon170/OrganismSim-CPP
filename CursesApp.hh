#pragma once

#include "Window.hh"
#include "CursesWindows.hh"

#include <unordered_map>

class CursesApp {
	std::unordered_map<std::string, Window*> screen;
	
public:
	CursesApp();
	~CursesApp();

	void addWindow(std::string identifier, Window*);
	void addWindow(Window*);

	void addWindows(std::initializer_list<Window*> windows) {
		for (auto window: windows)
			addWindow(window);
	}
	
	Window& get(std::string);
	void display();
	void readjust();
	void clear();
	void destroy();
};
