
#include <UI/Map/Cell.h>
#include <UI/Button.h>
#include <iostream>



void Cell::setChecker(sf::Color checker_color) {
	
}
Cell::Cell(sf::Vector2f position, sf::Color cell_color) :Button(position, {50,50}, cell_color) {
}
Cell::Cell():Button({0,0}) {
}