#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/GameBoardController.h"
#include "../include/Core/AssetManager.h"
#include<vector>
// состояние конца игры
enum CheckersResult {
	WIN_WHITE, // Победа белых
	WIN_BLACK, // Победа черных
	PAT, // Пат
	CONTINUE, // Игра продолжается
	LOSE_WHITE, // Сдался белый
	LOSE_BLACK // Сдался черный
};
// Структура для хранения координат
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
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, AssetManager* assets,bool ai = false);
	void update_input(sf::Vector2f position);
	ColorChecker getCurrentPlayer();
	// Функция  перезапуска контроллера 
	void reset();
	// Проверка конца игры
	CheckersResult checking_end();
	// Временно
	std::vector<std::vector<int>> int_grid;
private:
	// Указатель на менеджер пакетов
	AssetManager* assets;
	// Цвет текущего игрока
	ColorChecker current_player = ColorChecker::Black;
	// Цвет предыдущего игрока 
	ColorChecker previous_player = ColorChecker::Black;
	// Цвет который показывается в интерфейсе 
	ColorChecker show_player= ColorChecker::White;
	// Уничтожение фигуры
	void destroy_figure(std::pair<int, int>coordinate);
	// Функция проверки возможности взятия
	// Возвращает структуру CaptureMove
	std::vector<CaptureMove>  check_grid( std::pair<int, int> coordinate_start);
	// Указатель на игровое поле
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// Координаты выбора шашки
	std::pair<int, int> coordinate_start;
	// Координаты хода шашки
	std::pair<int, int> coordinate_end;
	// Нажата ли шашка
	bool pressed_checker = false;
	// Количество черных фигур
	int count_black_figure = 12;
	// Количество белых фигур 
	int count_white_figure = 12;
	bool check_pat = false;
	void checking_pat();
	//Возможно ли так походить
	bool is_move_checker(const std::pair<int, int> &coordinate_start,  const std::pair<int, int> &coordinate_end);
	// Функция хода шашки из координат начала в координаты конца
	void move_checker( int speed = 30);
	CheckersResult end_state = CONTINUE;
	// Переход от шашки к дамке 
	void changing_checkers(ColorChecker current_player, const std::pair<int, int>& coordinate_end);
	bool ai = false;
	ColorChecker ai_color = ColorChecker::Black;
	
};