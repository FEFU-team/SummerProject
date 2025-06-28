#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/AssetManager.h"
#include<vector>
#include "RuleEngine.h"


// состояние конца игры
enum CheckersResult {
	WIN_WHITE, // Победа белых
	WIN_BLACK, // Победа черных
	PAT, // Пат
	CONTINUE, // Игра продолжается
	LOSE_WHITE, // Сдался белый
	LOSE_BLACK // Сдался черный
};

// Управление игровым полем
// Контролирование правил игры
class GameBoardController {
public:
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, AssetManager* assets, bool ai = false);
	void update_input(sf::Vector2f position);
	ColorChecker getCurrentPlayer() const;
	// Функция  перезапуска контроллера 
	void reset();
	// Проверка конца игры
	CheckersResult checking_end();
	// Обновляем ход ai
	void update_ai();
	// Включен ли ai mode
	bool isAiMode() const;
	// Задать ai mode
	void setAiMode(bool mode);
	// Временно
	std::vector<std::vector<int>> int_grid;
private:
	// Указатель на менеджер пакетов
	AssetManager* assets;
	// Цвет текущего игрока
	ColorChecker current_player = ColorChecker::White;
	// Цвет предыдущего игрока 
	ColorChecker previous_player = ColorChecker::Black;
	// Цвет который показывается в интерфейсе 
	ColorChecker show_player = ColorChecker::White;
	// Уничтожение фигуры
	void destroy_figure(std::pair<int, int>coordinate);
	// Указатель на игровое поле
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// Координаты выбора шашки
	std::pair<int, int> coordinate_start;
	// Координаты хода шашки
	std::pair<int, int> coordinate_end;
	// Пат ли сейчас
	bool pat = false;
	// Нажата ли шашка
	bool pressed_checker = false;
	// Количество черных фигур
	int count_black_figure = 12;
	// Количество белых фигур 
	int count_white_figure = 12;
	// Функция хода шашки из координат начала в координаты конца
	void move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end, int speed = 30);

	CheckersResult end_state = CONTINUE;
	// Переход от шашки к дамке 
	bool changing_checkers(ColorChecker current_player, const std::pair<int, int>& coordinate_end);
	// Режим игры c ai
	bool ai_mode = false;
	// Цвет шашек ai
	ColorChecker ai_player = ColorChecker::Black;;

};