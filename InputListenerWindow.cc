#include "InputListenerWindow.hh"

InputListenerWindow::InputListenerWindow(std::string title)
	: Window(title, 1, 1, 0, 0) {
	curs_set(0);
	enableListening();
}
