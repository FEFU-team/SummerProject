#include "../include/Core/Ai.h"

std::pair<int,int> Ai::do_move()
{
	/*
	sf::Vector2f position;
	position.x = rand()%8;
	position.y = rand()%8;
	return {position.x,position.y};

	*/
	return { 0,0 };
}

void Ai::update_int_grid(std::vector<std::vector<int>>* int_grid)
{
	this->int_grid = *int_grid;
}

std::pair<float, Move> Ai::miniMax(int depth, bool max_player)
{

	return std::pair<float, Move>();
}

Ai::Ai()
{
	
}



float Ai::evaluate_position()
{
	float eval = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (int_grid[i][j] == 1) {
				eval -= matrix_cost[i][j]*checker_value;
			}
			else if (int_grid[i][j] == 3) {
				eval -= matrix_cost[i][j] * queen_value;
			}
			else if (int_grid[i][j] == 2) {
				eval += matrix_cost[i][j] * checker_value;
			}
			else if (int_grid[i][j] == 4) {
				eval += matrix_cost[i][j] * queen_value;
			}
		}
	}
	return eval;
}

Move Ai::active_search()
{
	std::vector<Move> all_move =  RuleEngine::get_all_move(int_grid);
	if (all_move.size() == 1) {
		return all_move[0];
	}
	else {
		for (int i = 0; i < all_move.size(); i++) {
			
		}
	}
}

void Ai::move(std::pair<int, int> coordinate_start, std::pair<int, int> coordinate_end)
{
	int checkers = int_grid[coordinate_start.first][coordinate_start.second];
	int_grid[coordinate_start.first][coordinate_start.second] = 0;
	int_grid[coordinate_end.first][coordinate_end.second] = checkers;
}

void Ai::undo_move(std::pair<int, int> coordinate_end,std::pair<int, int> coordinate_start)
{
	int checkers = int_grid[coordinate_end.first][coordinate_end.second];
	int_grid[coordinate_end.first][coordinate_end.second] = 0;
	int_grid[coordinate_start.first][coordinate_start.second] = checkers;
}
