#pragma once

#include "Window.hh"

class InputListenerWindow final : public Window {
public:
	InputListenerWindow(std::string title);

	virtual void clear() override {}
	virtual void display() override {}
	virtual void addItem(char const*) override {};
};
