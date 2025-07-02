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
	std::vector<CaptureMove>  check_capture_all( const std::pair<int, int>& coordinate, const  std::vector<std::vector<int>>& int_grid);
	// Вариант взятие для повторного взятие
	// queen_take для повторного вызова функции 
	std::vector<CaptureMove> check_capture(const std::pair<int, int>& coordinate, const  std::vector<std::vector<int>>& int_grid);
	//Возможно ли так походить
	bool is_move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end, const  std::vector<std::vector<int>>& int_grid);
	// Пат или сейчас
	bool  is_pat(const  std::vector<std::vector<int>>& int_grid);


	// Проверяем есть ли ходы для фигур
	// Возращаем множество ходов 
	std::vector<Move> get_all_move(const  std::vector<std::vector<int>>& int_grid,bool color=false);


};
