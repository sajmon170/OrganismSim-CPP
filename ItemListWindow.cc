#include "ItemListWindow.hh"

void ItemListWindow::clear() {
	items.clear();
}

void ItemListWindow::display() {
	erase();
	
	int printed = 0;
	for (auto& element: items) {
		auto formatted = "- " + element;
		if (formatted.length() < getContentSizeX()) {
			print((formatted + '\n').c_str());
		}
		else {
			std::string ellipsis = "...";
			auto cut = formatted.substr(0, getContentSizeX() - ellipsis.size());
			print((cut + ellipsis + '\n').c_str());
		}

		if (++printed >= getContentSizeY())
			break;
	}
	BorderedWindow::display();
}

void ItemListWindow::addItem(char const* item) {
	items.push_back(item);
}
