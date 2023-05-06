#pragma once

#include <curses.h>
#include <string>

class Window {
	WINDOW* window;
	std::string title;
	int max_y, max_x;
	int size_y, size_x;
	int pos_y, pos_x;
	bool listening_enabled;
	
protected:
	void move(int y, int x);
	void refresh();

	virtual Window* getMainWindow();
	
	void print(char const*);
	void print(Window*, char const*);
	
	template <typename... Args>
	void print(char const* fmt, Args... args) {
		print(getMainWindow(), fmt, &args...);
	}
	
	template <typename... Args>
	void print(Window* win, char const* fmt, Args... args) {
		wprintw(win->window, fmt, &args...);
	}
	
	template <typename... Args>
	void print(int y, int x, char const* fmt, Args... args) {
		print(getMainWindow(), y, x, fmt, &args...);
	}

	template <typename... Args>
	void print(Window* win, int y, int x, char const* fmt, Args... args) {
		mvwprintw(win->window, y, x, fmt, &args...);
	}

	void drawBorder();
	void eraseBorder();

public:
	Window(std::string wintitle, int height, int width, int posy, int posx);
	virtual ~Window();

	inline int getPosY() const {
		return pos_y;
	}
	inline int getPosX() const {
		return pos_x;
	}
	inline int getSizeY() const {
		return size_y;
	}
	inline int getSizeX() const {
		return size_x;
	}
	inline char const* getTitle() const {
		return title.c_str();
	}
	inline void enableListening() {
		listening_enabled = true;
	}
	inline void disableListening() {
		listening_enabled = false;
	}
	inline int getChar() {
		if (listening_enabled)
			return wgetch(window);
		else
			return -1;
	}
	inline void restoreChar(int c) {
		if (listening_enabled)
			ungetch(c);
	}
	
	virtual void clear();
	virtual void erase();
	virtual void display();
	virtual void readjust();
	virtual void addItem(char const*);
	virtual void addItems(std::initializer_list<char const*>);
};
