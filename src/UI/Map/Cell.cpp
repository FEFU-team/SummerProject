
#include <UI/Map/Cell.h>
#include <UI/Button.h>
#include <iostream>
Cell::Cell(sf::Vector2f positions, sf::Color cell_color, Checker* checker) :Button(positions, size, cell_color) {
	
	shape.setSize({ 50,50 });
	if (checker != nullptr) {
		isBeChecker = true;
	}
	this->checker = checker;
	
}
Cell::Cell():Button({0,0}) {

}