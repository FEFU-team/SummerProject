#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/GameBoardController.h"
class GameBoardController {
public:
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid);
	void update_input(sf::Vector2f position);
	//bool game_end();
	//void update_animation(float delta_time);
private:
	// Уничтожение фигуры
	void destroy_figure(std::pair<int, int>coordinate);
	void update_int_grid();
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	std::pair<int, int> coordinate_begin; 
	std::pair<int, int> coordinate_end;
	bool pressed_checker = false;
	std::vector<std::vector<int>> int_grid;
	//Возможно ли так походить
	bool is_move_checker();

	void move_checker();

};