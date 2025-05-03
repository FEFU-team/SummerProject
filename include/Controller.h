#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
class Controller {
public:
	void update();
	void changeColor(Cell* cell);
	Controller();
};