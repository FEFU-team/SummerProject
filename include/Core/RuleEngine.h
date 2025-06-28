#pragma once
#include <vector>
// ��������� ��� �������� ���������
struct CaptureMove
{
	// ���������� ������ ������ 
	std::pair<int, int> coordinate_start;
	// ����������   ...
	std::pair<int, int> coordinate_end;
	// ���������� ������ ������ 
	std::pair<int, int> coordinate_take;
	// ���� �� ������ ������
	bool queen_take = false;


};
struct Move
{
	std::pair<int, int> coordinate_start;

	// ���������� ������ ������ 
	std::pair<int, int> coordinate_take = { -1,-1 };

	std::pair<int, int> coordinate_end;

};
namespace RuleEngine {
	// ��� �������� ������ �����  ��� �����
	// queen_take ��� ���������� ������ ������� 
	std::vector<CaptureMove>  check_capture( const std::pair<int, int>& coordinate, const  std::vector<std::vector<int>>& int_grid, bool queen_take = false);
	//�������� �� ��� ��������
	bool is_move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end, const  std::vector<std::vector<int>>& int_grid);
	// ��� ��� ������
	bool  is_pat(const  std::vector<std::vector<int>>& int_grid);


	// ��������� ���� �� ���� ��� �����
	// ��������� ��������� ����� 
	std::vector<Move> get_all_move(const  std::vector<std::vector<int>>& int_grid,bool color=false);


};
