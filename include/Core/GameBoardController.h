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
// ���� ������
enum  class ColorPlayer {
	White, Black
};
// ���������� ������� �����
// ��������������� ������ ����
class GameBoardController {
public:
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid);
	void update_input(sf::Vector2f position);
	ColorPlayer getCurrentPlayer();
private:
	// ���� �������� ������
	ColorPlayer current_player = ColorPlayer::White;
	// ����������� ������
	void destroy_figure(std::pair<int, int>coordinate);
	CaptureMove check_grid();
	// ��������� �� ������� ����
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// ���������� ������ �����
	std::pair<int, int> coordinate_start;
	// ���������� ���� �����
	std::pair<int, int> coordinate_end;
	// ���� �����
	ColorChecker color_checker;
	// ������ �� �����
	bool pressed_checker = false;
	std::vector<std::vector<int>> int_grid;
	//�������� �� ��� ��������
	bool is_move_checker(ColorChecker color_checker);
	// ������� ���� ����� �� ��������� ������ � ���������� �����
	void move_checker( int speed = 30);

};