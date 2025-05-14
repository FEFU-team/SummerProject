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
	//������ �� ������ ��� ���� �����
	bool checker_pressed = false;
	// ������ �� ������� ������
	bool cell_pressed = false;
	//����� � ����� ������������� �������
	std::vector<std::vector<int>> int_grid;
	//�������� �� ��� ��������
	bool is_move_checker(std::pair<int, int> �ordinat_begin, std::pair<int, int> �ordinat_end);

};