#include "Window.hh"

Window::Window(std::string wintitle, int y, int x, int posy, int posx)
	: size_y(y), size_x(x), pos_y(posy), pos_x(posx), title(wintitle) {

	window = newwin(size_y, size_x, pos_y, pos_x);
	max_y = getmaxy(stdscr);
	max_x = getmaxx(stdscr);
	listening_enabled = false;
	keypad(window, true);
}

Window::~Window() {
	delwin(window);
}

void Window::move(int y, int x) {
	pos_y = y;
	pos_x = x;
	mvwin(window, y, x);
}

void Window::refresh() {
	wrefresh(window);
}

Window* Window::getMainWindow()  {
	return this;
}

void Window::print(char const* str) {
	print(getMainWindow(), str);
}

void Window::print(Window* win, char const* str) {
	waddstr(win->window, str);
}

void Window::drawBorder() {
	box(window, 0, 0);
}

void Window::eraseBorder() {
	wborder(window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
}

void Window::display() {
	wrefresh(window);
}

void Window::readjust() {
	int new_y, new_x;
	getmaxyx(stdscr, new_y, new_x);

	double ratio_y = double(new_y)/max_y;
	double ratio_x = double(new_x)/max_x;

	max_y = new_y;
	max_x = new_x;

	size_y *= ratio_y;
	size_x *= ratio_x;

	pos_y *= ratio_y;
	pos_x *= ratio_x;
	
	wresize(window, size_y, size_x);
	mvwin(window, pos_y, pos_x);
	clear();
	wrefresh(window);
}

void Window::addItem(char const* item) {
	print(item);
}

void Window::addItems(std::initializer_list<char const*> items) {
	for (auto& item: items)
		addItem(item);
}

void Window::clear() {
	werase(window);
}

void Window::erase() {
	Window::clear();
	Window::display();
}
