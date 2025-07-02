#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/AssetManager.h"
#include<vector>
#include "RuleEngine.h"
#include "Ai.h"


// ��������� ����� ����
enum CheckersResult {
	WIN_WHITE, // ������ �����
	WIN_BLACK, // ������ ������
	PAT, // ���
	CONTINUE, // ���� ������������
	LOSE_WHITE, // ������ �����
	LOSE_BLACK // ������ ������
};
class Ai;
// ���������� ������� �����
// ��������������� ������ ����
class GameBoardController {
public:
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, AssetManager* assets, bool ai_mode = false,Ai* ai=nullptr);
	void update_input(sf::Vector2f position);
	ColorChecker getCurrentPlayer() const;
	// �������  ����������� ����������� 
	void reset();
	// �������� ����� ����
	CheckersResult checking_end();
	// ��������� ��� ai
	void update_ai();
	// ������� �� ai mode
	bool isAiMode() const;
	// ������ ai mode
	void setAiMode(bool mode);
	// ��������
	std::vector<std::vector<int>> int_grid;
private:
	// ������������� ������ 
	bool repeat_capture = false;
	std::pair<int, int> repeat_coordinate;
	// ��������� �� ������
	bool move = false;
	int k = 0;
	Ai* ai;
	// ��������� �� �������� �������
	AssetManager* assets;
	// ���� �������� ������
	ColorChecker current_player = ColorChecker::White;
	// ���� ����������� ������ 
	ColorChecker previous_player = ColorChecker::Black;
	// ���� ������� ������������ � ���������� 
	ColorChecker show_player = ColorChecker::White;
	// ����������� ������
	void destroy_figure(std::pair<int, int>coordinate);
	// ��������� �� ������� ����
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// ���������� ������ �����
	std::pair<int, int> coordinate_start;
	// ���������� ���� �����
	std::pair<int, int> coordinate_end;
	// ��� �� ������
	bool pat = false;
	// ������ �� �����
	bool pressed_checker = false;
	// ���������� ������ �����
	int count_black_figure = 12;
	// ���������� ����� ����� 
	int count_white_figure = 12;
	// ������� ���� ����� �� ��������� ������ � ���������� �����
	void move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end, int speed = 30);

	CheckersResult end_state = CONTINUE;
	// ������� �� ����� � ����� 
	bool changing_checkers(ColorChecker current_player, const std::pair<int, int>& coordinate_end);
	// ����� ���� c ai
	bool ai_mode = false;
	// ���� ����� ai
	ColorChecker ai_player = ColorChecker::Black;;

};