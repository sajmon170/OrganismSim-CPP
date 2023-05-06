#pragma once

#include "Window.hh"

#include <vector>
#include <string>

class StatusBarWindow : public Window {
	std::vector<std::string> items;
	
public:
	StatusBarWindow(std::string wintitle, int width, int posy, int posx)
		: Window(wintitle, 1, width, posy, posx) {}

	virtual void clear() override;
	virtual void display() override;
	virtual void addItem(char const*) override;
};
