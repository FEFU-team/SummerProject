#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
class Controller {
public:
	void updateEvent(sf::Event);
	void changeColor(Cell* cell);
	Controller();
};