#include "StatusBarWindow.hh"

void StatusBarWindow::clear() {
	//	items.clear();
	Window::clear();
}

void StatusBarWindow::display() {
	for (auto& element: items)
		print((element + "  ").c_str());

	// Move this to a dedicated method inside the Window class:
	// Window::SetAttributes();
	// or maybe move attributes to the printing method along
	// with color data?
	mvchgat(getPosY(), getPosX(), getSizeX(), A_REVERSE, 0, NULL);

	Window::display();
}

void StatusBarWindow::addItem(char const* str) {
	items.push_back(str);
}
