#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/GameBoardController.h"


struct CaptureMove
{
	std::pair<int, int> coordinate_start;
	std::pair<int, int> coordinate_end;
	std::pair<int, int> coordinate_take;


};
// Цвет игрока
enum  class ColorPlayer {
	White, Black
};
// Управление игровым полем
// Контролирование правил игры
class GameBoardController {
public:
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid);
	void update_input(sf::Vector2f position);
	ColorPlayer getCurrentPlayer();
private:
	// Цвет текущего игрока
	ColorPlayer current_player = ColorPlayer::White;
	// Уничтожение фигуры
	void destroy_figure(std::pair<int, int>coordinate);
	CaptureMove check_grid();
	// Указатель на игровое поле
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// Координаты выбора шашки
	std::pair<int, int> coordinate_start;
	// Координаты хода шашки
	std::pair<int, int> coordinate_end;
	// Цвет шашки
	ColorChecker color_checker;
	// Нажата ли шашка
	bool pressed_checker = false;
	std::vector<std::vector<int>> int_grid;
	//Возможно ли так походить
	bool is_move_checker(ColorChecker color_checker);
	// Функция хода шашки из координат начала в координаты конца
	void move_checker( int speed = 30);

};