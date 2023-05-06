#include "BorderedWindow.hh"

BorderedWindow::BorderedWindow(std::string title, int y, int x, int py, int px)
	: Window::Window(title, y, x, py, px) {
	content = new Window(title + "_content", y-2, x-2, py + 1, px + 1);
}

Window* BorderedWindow::getMainWindow() {
	return content;
}

BorderedWindow::~BorderedWindow() {
	delete content;
}

int BorderedWindow::getContentSizeY() const {
	return getSizeY() - 2;
}

int BorderedWindow::getContentSizeX() const {
	return getSizeX() - 2;
}

void BorderedWindow::clear() {
	content->clear();
}

void BorderedWindow::erase() {
	content->erase();
	Window::erase();
}

void BorderedWindow::display() {
	drawBorder();
	print(this, 0, 2, getTitle());
	Window::display();
	content->display();
}

void BorderedWindow::readjust() {
	Window::readjust();
	content->readjust();
}

void BorderedWindow::addItem(char const* item) {
	content->addItem(item);
}

