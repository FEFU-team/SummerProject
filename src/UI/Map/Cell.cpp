
#include <UI/Map/Cell.h>
#include <UI/Button.h>
#include <iostream>
Cell::Cell(sf::Vector2f positions, sf::Color cell_color, Checker* checker) :Button(positions, size, cell_color) {
	
	shape.setSize({ 50,50 });
	this->checker = checker;
	if (checker != nullptr) {
		is_be_checker = true;
	}

	
}
Cell::Cell():Button({0,0}) {

}