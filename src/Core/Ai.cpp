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

void Ai::active_search()
{

}
