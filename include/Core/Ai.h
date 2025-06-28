
#pragma once
#include <SFML/Graphics.hpp>
#include "GameBoardController.h"
#include "RuleEngine.h"
#include<iostream>
class Ai {
public:

    // Move
	std::pair<int, int> do_move();
    void update_int_grid(std::vector<std::vector<int>> *int_grid);
    std::pair<float, Move> miniMax(int depth, bool max_player);
	Ai();
private:
    std::vector<std::vector<int>> int_grid;
    int checker_value = 10; // стоимость простой шашки
    int queen_value = 25; // стоимость дамки
    const int matrix_cost[8][8] = {
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {2,2,2,2,2,2,2,2},
        {3,3,1,4,4,3,3,3},
        {3,3,3,4,4,3,3,3},
        {2,2,2,2,2,2,2,2},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
    };
    float evaluate_position();
    Move active_search();
    void move(std::pair<int,int> coordinate_start, std::pair<int, int> coordinate_end);
    void undo_move(std::pair<int, int> coordinate_end,std::pair<int, int> coordinate_start);
    

};