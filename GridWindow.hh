#pragma once

#include "BorderedWindow.hh"
#include "Vector2.hh"

#include <vector>
#include <string>

class GridWindow : public BorderedWindow {
	std::vector<std::string> cells;
	
protected:
	inline std::string& getCell(int row, int col) {
		return cells[row*getSizeX() + col];
	}

	void fillScreen(char const*);
	
public:
	GridWindow(std::string wintitle, int y, int x, int posy, int posx);
	
	virtual int getContentSizeX() const override;
	virtual void clear() override;
	virtual void display() override;
	virtual void readjust() override;
	//virtual void addItem(char const*) override;
	virtual void addItem(Vector2 const&, char const*);
};
