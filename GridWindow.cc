#include "GridWindow.hh"

GridWindow::GridWindow(std::string wintitle, int y, int x, int posy, int posx)
	: BorderedWindow::BorderedWindow(wintitle, y, x, posy, posx) {
	fillScreen("  ");
}

void GridWindow::fillScreen(char const* str) {
	for (int i=0; i<getSizeX()*getSizeY(); i++)
		cells.push_back(str);
}

int GridWindow::getContentSizeX() const {
	return BorderedWindow::getContentSizeX() / 2;
}

void GridWindow::clear() {
	cells.clear();
	BorderedWindow::clear();
	fillScreen("  ");
}

void GridWindow::display() {
	for (int row=0; row<getSizeY(); row++)
		for (int col=0; col<0.5*getSizeX(); col++)
			print(row, 2*col, getCell(row, col).c_str());
	
	BorderedWindow::display();
}

void GridWindow::readjust() {
	BorderedWindow::readjust();
	
	cells.clear();
	fillScreen("  ");
}

void GridWindow::addItem(Vector2 const& pos, char const* str) {
	getCell(pos.getY(), pos.getX()) = str;
}
