#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
class GameBoardController {
public:
	int x = 10;
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid);
	void update_input(std::vector<std::vector<std::unique_ptr<Cell>>> *grid, sf::Vector2f position);
private:
	int xc = 10;
	//Нажали ли ячейка где есть шашка
	bool checker_pressed = false;
	// Нажали ли пусткая ячейка
	bool cell_pressed = false;
	//Сетка в ввиде целочисленной матрици
	std::vector<std::vector<int>> int_grid;
	//Возможно ли так походить
	bool is_move_checker(std::pair<int, int> сordinat_begin, std::pair<int, int> сordinat_end);

};