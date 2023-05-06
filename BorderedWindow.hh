#pragma once

#include "Window.hh"

class BorderedWindow : public Window {
	Window* content;

protected:
	virtual Window* getMainWindow() override;

public:
	BorderedWindow(std::string wintitle, int y, int x, int posy, int posx);
	~BorderedWindow() override;

	virtual int getContentSizeY() const;
	virtual int getContentSizeX() const;

	virtual void clear() override;
	virtual void erase() override;
	virtual void display() override;
	virtual void readjust() override;
	virtual void addItem(char const*) override;
};
