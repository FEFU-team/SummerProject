#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/GameBoardController.h"


struct CaptureMove
{
	// Координаты выбора фигуры 
	std::pair<int, int> coordinate_start;
	// Координаты   ...
	std::pair<int, int> coordinate_end;
	// Координаты взятия фигуры 
	std::pair<int, int> coordinate_take;


};
// Управление игровым полем
// Контролирование правил игры
class GameBoardController {
public:
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid);
	void update_input(sf::Vector2f position);
	ColorChecker getCurrentPlayer();
private:
	// Цвет текущего игрока
	ColorChecker current_player;
	ColorChecker previous_player = ColorChecker::Black;
	// Уничтожение фигуры
	void destroy_figure(std::pair<int, int>coordinate);



	std::vector<CaptureMove>  check_grid(ColorChecker current_player);



	// Указатель на игровое поле
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// Координаты выбора шашки
	std::pair<int, int> coordinate_start;
	// Координаты хода шашки
	std::pair<int, int> coordinate_end;
	// Нажата ли шашка
	bool pressed_checker = false;
	std::vector<std::vector<int>> int_grid;
	//Возможно ли так походить
	bool is_move_checker(ColorChecker color_checker);
	// Функция хода шашки из координат начала в координаты конца
	void move_checker( int speed = 30);

};