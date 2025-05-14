#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
class GameBoardController {
public:
	int x = 10;
	GameBoardController();
	void update_input(std::vector<std::vector<std::unique_ptr<Cell>>> *grid, sf::Vector2f position);
private:
	int xc = 10;
	//Нажали ли ячейка где есть шашка
	bool checker_pressed = false;
	// Нажали ли пусткая ячейка
	bool cell_pressed = false;

};