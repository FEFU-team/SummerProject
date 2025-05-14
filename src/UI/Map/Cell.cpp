
#include <UI/Map/Cell.h>
#include <UI/Button.h>
#include <iostream>


void Cell::setChecker(sf::Color color) {
   checker_ptr = std::make_unique<Checker>(getPosition(), color);
	is_be_checker = true;
}
Checker* Cell::getChecker() {
	return checker_ptr.get();
}
bool Cell::isBeChecker() {
	return is_be_checker;
}
Cell::Cell(sf::Vector2f position, sf::Color cell_color) :Button(position, {100,100}, cell_color) {
}
Cell::Cell():Button({0,0}) {
}