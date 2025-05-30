#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/GameBoardController.h"


struct CaptureMove
{
	// ���������� ������ ������ 
	std::pair<int, int> coordinate_start;
	// ����������   ...
	std::pair<int, int> coordinate_end;
	// ���������� ������ ������ 
	std::pair<int, int> coordinate_take;


};
// ���������� ������� �����
// ��������������� ������ ����
class GameBoardController {
public:
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid);
	void update_input(sf::Vector2f position);
	ColorChecker getCurrentPlayer();
private:
	// ���� �������� ������
	ColorChecker current_player;
	ColorChecker previous_player = ColorChecker::Black;
	// ����������� ������
	void destroy_figure(std::pair<int, int>coordinate);



	std::vector<CaptureMove>  check_grid(ColorChecker current_player);



	// ��������� �� ������� ����
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// ���������� ������ �����
	std::pair<int, int> coordinate_start;
	// ���������� ���� �����
	std::pair<int, int> coordinate_end;
	// ������ �� �����
	bool pressed_checker = false;
	std::vector<std::vector<int>> int_grid;
	//�������� �� ��� ��������
	bool is_move_checker(ColorChecker color_checker);
	// ������� ���� ����� �� ��������� ������ � ���������� �����
	void move_checker( int speed = 30);

};