
#include <UI/Map/Cell.h>
#include "../include/UI//Buttons/Button.h"
#include <iostream>


sf::Vector2f Cell::getCenter()
{
	return center;
}

void Cell::transferChecker(std::unique_ptr<Checker> checker)
{
	is_be_checker = true;
	checker_ptr = std::move(checker);
}

std::unique_ptr<Checker> Cell::releaseChecker()
{
	is_be_checker = false;
	return std::move(checker_ptr);
}

void Cell::setChecker(sf::Color color) {
   checker_ptr = std::make_unique<Checker>(position, color);
	is_be_checker = true;
}
Checker* Cell::getChecker() {
	return checker_ptr.get();
}
bool Cell::isBeChecker() {
	return is_be_checker;
}
Cell::Cell(sf::Vector2f position, sf::Color cell_color) :Button(position, {100,100}, cell_color) {
	sf::FloatRect bounds = shape.getGlobalBounds();
	center = bounds.getCenter();
	this->position = position;
}
Cell::Cell():Button({0,0}) {
}