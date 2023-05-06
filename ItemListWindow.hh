#pragma once

#include "BorderedWindow.hh"
#include <vector>

class ItemListWindow : public BorderedWindow {
	std::vector<std::string> items;
	
public:
	using BorderedWindow::BorderedWindow;

	virtual void clear() override;
	virtual void display() override;
	virtual void addItem(char const*) override;
};
