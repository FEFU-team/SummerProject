#pragma once
#include <vector>
// Структура для хранения координат
struct CaptureMove
{
	// Координаты выбора фигуры 
	std::pair<int, int> coordinate_start;
	// Координаты   ...
	std::pair<int, int> coordinate_end;
	// Координаты взятия фигуры 
	std::pair<int, int> coordinate_take;
	// Были ли взятие дамкой
	bool queen_take = false;


};
struct Move
{
	std::pair<int, int> coordinate_start;

	// Координаты взятия фигуры 
	std::pair<int, int> coordinate_take = { -1,-1 };

	std::pair<int, int> coordinate_end;

};
namespace RuleEngine {
	// Все варианты взятие шашки  или дамки
	// queen_take для повторного вызова функции 
	std::vector<CaptureMove>  check_capture( const std::pair<int, int>& coordinate, const  std::vector<std::vector<int>>& int_grid, bool queen_take = false);
	//Возможно ли так походить
	bool is_move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end, const  std::vector<std::vector<int>>& int_grid);
	// Пат или сейчас
	bool  is_pat(const  std::vector<std::vector<int>>& int_grid);


	// Проверяем есть ли ходы для фигур
	// Возращаем множество ходов 
	std::vector<Move> get_all_move(const  std::vector<std::vector<int>>& int_grid,bool color=false);


};
