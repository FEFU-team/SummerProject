#pragma once
#include <Main.hpp>
#include <UI/Map/Cell.h>
#include "../include/Core/GameBoardController.h"
#include "../include/Core/AssetManager.h"
#include<vector>
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
// ��������� ��� �������� ���������
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
	GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, AssetManager* assets,bool ai = false,Ai* computer = nullptr);
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
	void setAiMode(bool mode );
	// ��������
	std::vector<std::vector<int>> int_grid;
private:
	// Ai
	Ai* computer;
	// ��������� �� �������� �������
	AssetManager* assets;
	// ���� �������� ������
	ColorChecker current_player = ColorChecker::White;
	// ���� ����������� ������ 
	ColorChecker previous_player = ColorChecker::Black;
	// ���� ������� ������������ � ���������� 
	ColorChecker show_player= ColorChecker::White;
	// ����������� ������
	void destroy_figure(std::pair<int, int>coordinate);
	// ������� �������� ����������� ������
	// ���������� ��������� CaptureMove
	std::vector<CaptureMove>  check_grid( std::pair<int, int> coordinate_start);
	// ��������� �� ������� ����
	std::vector<std::vector<std::unique_ptr<Cell>>>* grid_ptr;
	// ���������� ������ �����
	std::pair<int, int> coordinate_start;
	// ���������� ���� �����
	std::pair<int, int> coordinate_end;
	// ������ �� �����
	bool pressed_checker = false;
	// ���������� ������ �����
	int count_black_figure = 12;
	// ���������� ����� ����� 
	int count_white_figure = 12;
	bool check_pat = false;
	void checking_pat();
	//�������� �� ��� ��������
	bool is_move_checker(const std::pair<int, int> &coordinate_start,  const std::pair<int, int> &coordinate_end);
	// ������� ���� ����� �� ��������� ������ � ���������� �����
	void move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end,int speed = 30);
	CheckersResult end_state = CONTINUE;
	// ������� �� ����� � ����� 
	void changing_checkers(ColorChecker current_player, const std::pair<int, int>& coordinate_end);
	// ����� ���� c ai
	bool ai_mode = false;
	// ���� ����� ai
	ColorChecker ai_player = ColorChecker::Black;
	
};