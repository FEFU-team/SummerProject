
#pragma once
#include <SFML/Graphics.hpp>
#include "GameBoardController.h"
#include "RuleEngine.h"
#include<iostream>
class Ai {
public:

    // Move
	std::pair<int, int> do_move();
    void update_int_grid(const std::vector<std::vector<int>>& int_grid);
    std::pair<float, Move> miniMax(int depth, bool max_player);
	Ai();
    Move active_search();
private:
    std::vector<std::vector<int>> int_grid;
    int checker_value = 10; // ��������� ������� �����
    int queen_value = 25; // ��������� �����
    const float matrix_cost[8][8] = {
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,},
        {1,1,1,2,1,1,1,},
        {1,1,1,1,1,2,1,},
        {1,1,1,1,1,1,1,},
        {1,1,1,1,1,1,1,},
        {1,1,1,1,1,1,1,},
        {1,1,1,1,1,1,1,},
    };
    const float line_cost[8] = { 4,3,2,1,2,3,4,};
    float evaluate_position();
    void move(std::pair<int,int> coordinate_start, std::pair<int, int> coordinate_end);
    void undo_move(std::pair<int, int> coordinate_end,std::pair<int, int> coordinate_start);
    

};