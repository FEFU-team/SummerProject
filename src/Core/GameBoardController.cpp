
#include <iostream>
#include <Core/GameBoardController.h>

using namespace RuleEngine;



using namespace std;

GameBoardController::GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, AssetManager* assets, bool ai)
{
	this->assets = assets;
	this->grid_ptr = grid;
	this->ai_mode = ai;
	//this->ai = bot;
	// Создаем целочисленную матрицу 
	for (int i = 0; i < grid->size(); i++) {
		vector<int> line(grid->size(), 0);
		for (int j = 0; j < grid->size(); j++) {
			if((*grid)[i][j]->isBeChecker()){
				if ((*grid)[i][j]->getChecker()->getColorChecker() == ColorChecker::White) {
					line[j] = 1;
				}
				else {
					line[j] = 2;
				}
				
			}
			else {
				line[j] = 0;
			}
			
		}
		int_grid.push_back(line);
	}

	//for (int i = 0; i < grid->size(); i++) {
		//for (int j = 0; j < grid->size(); j++) {
		//	std::cout << int_grid[i][j] << " ";
		//}
		//std::cout << "" << std::endl;
	//}

}

void GameBoardController::update_input(sf::Vector2f position)
{
	if (current_player == ColorChecker::White) {
		cout << "current_player  White" << endl;
	}
	else {
		cout << " current_player  Black" << endl;
	}
	if (previous_player == ColorChecker::White) {
		cout << "previous_player White" << endl;
	}
	else {
		cout << " previous_player Black" << endl;
	}
	if (show_player == ColorChecker::White) {
		cout << " showplayer White" << endl;
	}
	else {
		cout << "showplayer Black" << endl;
	}
	for (int i = 0; i < grid_ptr->size(); i++) {
		for (int j= 0; j < grid_ptr->size(); j++) {
			if ((*grid_ptr)[i][j]->getChecker()) {
				if ((*grid_ptr)[i][j]->getChecker()->getColorChecker() == ai_player && ai_mode) {
					continue;
				}
			}
			
			if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() && pressed_checker == false && !(*grid_ptr)[i][j]->getChecker()->is_move()) {
				current_player = (*grid_ptr)[i][j]->getChecker()->getColorChecker();
				coordinate_start.first = i;
				coordinate_start.second = j;
				if ((*grid_ptr)[i][j]->isBeChecker()) {
					if ((*grid_ptr)[i][j]->getChecker()->is_active()) {
						if ((*grid_ptr)[i][j]->getChecker()->is_queen()) {
							(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("queen"), false);
						}
						else {
							(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker1"), false);
						}

						pressed_checker = false;
					}
					else {
						if ((*grid_ptr)[i][j]->getChecker()->is_queen()) {
							(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("queen_active"), true);
						}
						else {
							(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker_active"), true);
						}

						pressed_checker = true;
					}
				}
				break;
				
			}
			else if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() && !(*grid_ptr)[i][j]->getChecker()->is_move()) {
				current_player = (*grid_ptr)[i][j]->getChecker()->getColorChecker();

				if ((*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->is_queen()) {
					(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("queen"), false);
				}
				else {
					(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("checker1"), false);
				}
				
				if ((*grid_ptr)[i][j]->getChecker()->is_queen()) {
					(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("queen_active"), true);
				}
				else {
					(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker_active"), true);
				}
				
				coordinate_start.first = i;
				coordinate_start.second = j;
				
				break;
			}
			else if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() == false ) {
				coordinate_end.first = i;
				coordinate_end.second = j;
				if ((*grid_ptr)[coordinate_start.first][coordinate_start.second]->isBeChecker() && !(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->is_move()) {
					if ((*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->is_queen()) {
						(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("queen"), false);
					}
					else {
						(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("checker1"), false);
					}
				}
				
				if (pressed_checker && current_player != previous_player) {
					vector<CaptureMove> cor = check_capture(coordinate_start,int_grid);
					//vector<CaptureMove> cor;
					if ((*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->is_queen()) {
						(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("queen"), false);
					}
					else {
						(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("checker1"), false);
					}
					
					 pat = is_pat(int_grid);
					//cout << cor.coordinate_take.first << endl;
					//cout << cor.coordinate_take.second << endl;// )
					if ((is_move_checker(coordinate_start,coordinate_end,int_grid)) && cor.size() == 0) {
						move_checker(coordinate_start,coordinate_end);
						changing_checkers(current_player, coordinate_end);
						show_player = previous_player;
						previous_player = current_player;
						cout << "Simple move" << endl;
						
					}
					else {
						for (int i = 0; i < cor.size(); i++) {
							if (cor[i].coordinate_start == coordinate_start && cor[i].coordinate_end == coordinate_end) {
								move_checker(coordinate_start,coordinate_end);
								destroy_figure(cor[i].coordinate_take);
								// Решение бага #183 
								if (changing_checkers(current_player, coordinate_end)) {
									show_player = previous_player;
									previous_player = current_player;
									break;
								}
							
								if (check_capture(coordinate_end,int_grid,cor[i].queen_take).size() == 0) {
									show_player = previous_player;
									previous_player = current_player;
								}
							}
							else {
								cout << "Cor " << endl;
								cout << cor[i].coordinate_start.first << " " << cor[i].coordinate_start.second << endl;
								cout << cor[i].coordinate_take.first << " " << cor[i].coordinate_take.second << endl;
								cout << cor[i].coordinate_end.first << " " << cor[i].coordinate_end.second << endl;
							}
						}


					}


				}
				pressed_checker = false;

				break;
			}
		
		}
	}
}

ColorChecker GameBoardController::getCurrentPlayer() const
{
	return show_player;
}

void GameBoardController::reset()
{
	this->previous_player = ColorChecker::Black;
	this->show_player = ColorChecker::White;
	pressed_checker = false;
	for (int i = 0; i < grid_ptr->size(); i++) {
		for (int j = 0; j < this->grid_ptr->size(); j++) {
			if ((*grid_ptr)[i][j]->isBeChecker()) {
				if ((*grid_ptr)[i][j]->getChecker()->getColorChecker() == ColorChecker::White) {
					int_grid[i][j] = 1;
				}
				else {
					int_grid[i][j] = 2;
				}

			}
			else {
				int_grid[i][j] = 0;
			}

		}
	}
	for (int i = 0; i < grid_ptr->size(); i++) {
		for (int j = 0; j < grid_ptr->size(); j++) {
			std::cout << int_grid[i][j] << " ";
		}
		std::cout << "" << std::endl;
	}
}

void GameBoardController::destroy_figure(std::pair<int, int> coordinate)
{
	if (int_grid[coordinate.first][coordinate.second] == 1 || int_grid[coordinate.first][coordinate.second] == 3) {
		count_white_figure--;
	}
	else {
		count_black_figure--;
	}
	int_grid[coordinate.first][coordinate.second] = 0;
	(*grid_ptr)[coordinate.first][coordinate.second]->delete_checker();
}

void GameBoardController::move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end,int speed)
{
	int_grid[coordinate_start.first][coordinate_start.second] = 0;
	auto checker = (*grid_ptr)[coordinate_start.first][coordinate_start.second]->releaseChecker();
	if (checker->getColorChecker() == ColorChecker::Black && !checker->is_queen()) {
		int_grid[coordinate_end.first][coordinate_end.second] = 2;
	}
	else if (checker->getColorChecker() == ColorChecker::Black && checker->is_queen()) {
		int_grid[coordinate_end.first][coordinate_end.second] = 4;
	}
	else {
		if (checker->is_queen()) {
			int_grid[coordinate_end.first][coordinate_end.second] = 3;
		}
		else {
			int_grid[coordinate_end.first][coordinate_end.second] = 1;
		}
		
	}
	
	
	checker->start_move((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());

	
	(*grid_ptr)[coordinate_end.first][coordinate_end.second]->transferChecker(std::move(checker));
	
	
	//(*grid_ptr)[coordinate_end.first][coordinate_end.second]->getChecker()->setPosition((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());
}

CheckersResult GameBoardController::checking_end()
{
	cout << "Count black" << endl;
	cout << count_black_figure << endl;
	cout << "Count white" << endl;
	cout << count_white_figure << endl;
	if (count_black_figure == 0 && count_white_figure != 0) {
		return CheckersResult::WIN_WHITE;
	}
	else if (count_black_figure != 0 && count_white_figure == 0) {
		return CheckersResult::WIN_BLACK;
	}
	else if (pat) {
		return CheckersResult::PAT;
	}

	return CheckersResult::CONTINUE;
}


void GameBoardController::update_ai()
{
	
	
	if (show_player == ai_player) {
		show_player = previous_player;
		previous_player = ai_player;
		
	}
	

	
}

bool GameBoardController::isAiMode() const
{
	return ai_mode;
}

void GameBoardController::setAiMode(bool mode)
{
	this->ai_mode = mode;
}

bool GameBoardController::changing_checkers(ColorChecker current_player, const std::pair<int, int>& coordinate_end)
{
	if (coordinate_end.second == 0  && current_player == ColorChecker::White) {
			(*grid_ptr)[coordinate_end.first][coordinate_end.second]->getChecker()->becoming_queen(assets->getTexture("queen"));
			int_grid[coordinate_end.first][coordinate_end.second] = 3;
			return true;
			

	}
	if (coordinate_end.second == 7 && current_player == ColorChecker::Black) {
		(*grid_ptr)[coordinate_end.first][coordinate_end.second]->getChecker()->becoming_queen(assets->getTexture("queen"));
		int_grid[coordinate_end.first][coordinate_end.second] = 4;
		return true;
	}
	return false;
	
	
	
	
}

