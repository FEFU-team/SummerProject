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

void Ai::update_int_grid(const std::vector<std::vector<int>>& int_grid)
{
	int size = this->int_grid.size();
	if (size == 0) {
		for (int i = 0; i < 8; i++) {
			std::vector<int> v;
			for (int j = 0; j < 8; j++)
			{

				v.push_back(int_grid[i][j]);
			}
			this->int_grid.push_back(v);
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
			{
				this->int_grid[i][j] = int_grid[i][j];

			}
		}
	}
	
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
				eval -= matrix_cost[i][j]*checker_value * line_cost[7-i];
			}
			else if (int_grid[i][j] == 3) {
				eval -= matrix_cost[i][j] * queen_value;
			}
			else if (int_grid[i][j] == 2) {
				eval += matrix_cost[i][j] * checker_value * line_cost[ i];
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
	std::vector<Move> all_move = RuleEngine::get_all_move(int_grid, false);
	Move _move;
	if (all_move.size() == 1) {
		return all_move[0];
	}
	else {
		move(all_move[0].coordinate_start, all_move[0].coordinate_end);
		_move = all_move[0];
		// Текущий максимум 
		float m=evaluate_position();
		undo_move(all_move[0].coordinate_end, all_move[0].coordinate_start);
		for (int i = 1; i < all_move.size(); i++) {
			move(all_move[i].coordinate_start, all_move[i].coordinate_end);
			float eval = evaluate_position();
			m = std::max(m, eval);
			if (m == eval) {
				_move = all_move[i];
			}
			
			undo_move(all_move[0].coordinate_end, all_move[i].coordinate_start);
		}
		return _move;
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
