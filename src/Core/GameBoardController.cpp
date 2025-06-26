
#include <iostream>
#include <Core/GameBoardController.h>



using namespace std;

GameBoardController::GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, AssetManager* assets,bool ai, Ai* computer)
{
	this->assets = assets;
	this->grid_ptr = grid;
	this->ai_mode = ai;
	this->computer = computer;
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
	for (int i = 0; i < grid_ptr->size(); i++) {
		for (int j= 0; j < grid_ptr->size(); j++) {
			if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() && pressed_checker == false && !(*grid_ptr)[i][j]->getChecker()->is_move()) {
				current_player = (*grid_ptr)[i][j]->getChecker()->getColorChecker();
				if (current_player == ai_player && ai_mode) {
					break;
				}
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
					vector<CaptureMove> cor = check_grid(coordinate_start);
					if ((*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->is_queen()) {
						(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("queen"), false);
					}
					else {
						(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("checker1"), false);
					}
					checking_pat();
					//cout << cor.coordinate_take.first << endl;
					//cout << cor.coordinate_take.second << endl;// )
					if ((is_move_checker(coordinate_start,coordinate_end)) && cor.size() == 0) {
						move_checker(coordinate_start,coordinate_end);
						show_player = previous_player;
						previous_player = current_player;
						
					}
					else {
						for (int i = 0; i < cor.size(); i++) {
							if (cor[i].coordinate_start == coordinate_start && cor[i].coordinate_end == coordinate_end) {
								move_checker(coordinate_start,coordinate_end);
								destroy_figure(cor[i].coordinate_take);
								if (check_grid(coordinate_end).size() == 0) {
									show_player = previous_player;
									previous_player = current_player;
								}
							}
							else {
								
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
	// Ñòðàííîñòè 
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

vector<CaptureMove> GameBoardController::check_grid(std::pair<int, int> coordinate_start)
{
	vector<CaptureMove> coordinate;
	CaptureMove coordinate_elem;
	int size = int_grid.size();
	if (int_grid[coordinate_start.first][coordinate_start.second] == 1 || int_grid[coordinate_start.first][coordinate_start.second] == 3) {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (int_grid[i][j] == 1) {
					if (i - 2 >= 0 && j - 2 >= 0 && (int_grid[i - 1][j - 1] == 2 || int_grid[i - 1][j - 1] == 4) && int_grid[i - 2][j - 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i - 2,j - 2 };
						coordinate_elem.coordinate_take = { i - 1,j - 1 };
						coordinate.push_back(coordinate_elem);
					}
					if (i + 2 < size && j - 2 >= 0 && (int_grid[i + 1][j - 1] == 2 || int_grid[i + 1][j - 1] == 4) && int_grid[i + 2][j - 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i + 2,j - 2 };
						coordinate_elem.coordinate_take = { i + 1,j - 1 };
						coordinate.push_back(coordinate_elem);
					}
					if (i + 2 < size && j + 2 < size && (int_grid[i + 1][j + 1] == 2 || int_grid[i + 1][j + 1] == 4) && int_grid[i + 2][j + 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i + 2,j + 2 };
						coordinate_elem.coordinate_take = { i + 1,j + 1 };
						coordinate.push_back(coordinate_elem);
					}
					if (j + 2 < size && i - 2 >= 0 && (int_grid[i - 1][j + 1] == 2 || int_grid[i - 1][j + 1] == 4) && int_grid[i - 2][j + 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i - 2 ,j + 2 };
						coordinate_elem.coordinate_take = { i - 1,j + 1 };
						coordinate.push_back(coordinate_elem);
					}
				}
				for (int k = 1; k <= 7; k++) {
					if (int_grid[i][j] == 3) {
						if (i + k + 1 < size && j + k + 1 < size && int_grid[i + k - 1][j + k - 1] == 0 && ((int_grid[i + k][j + k] == 2 || int_grid[i + k][j + k] == 4))) {
							for (int l = 1; i + k + l < size && j + k + l < size; l++) {
								if (int_grid[i + k + 1][j + k + l] == 0) {
									coordinate_elem.coordinate_start = { i,j };
									coordinate_elem.coordinate_end = { i + k + l,j + k + l };
									coordinate_elem.coordinate_take = { i + k ,j + k };
									coordinate.push_back(coordinate_elem);
								}
								else {
									break;
								}
							}
						}
						if (i - k - 1 >= 0 && j + k + 1 < size && int_grid[i - k + 1][j + k - 1] == 0 && (int_grid[i - k][j + k] == 2 || int_grid[i - k][j + k] == 4)) {

							for (int l = 1; i - k - l >= 0 && j + k + l < size; l++) {
								if (int_grid[i - k - l][j + k + l] == 0) {
									coordinate_elem.coordinate_start = { i,j };
									coordinate_elem.coordinate_end = { i - k - l,j + k + l };
									coordinate_elem.coordinate_take = { i - k ,j + k };
									coordinate.push_back(coordinate_elem);
								}
								else {
									break;
								}
							}
						}
						if (i - k - 1 >= 0 && j - k - 1 >= 0 && int_grid[i - k + 1][j - k + 1] == 0 && (int_grid[i - k][j - k] == 2 || int_grid[i - k][j - k] == 4)) {
							for (int l = 1; i - k - l >= 0 && j - k - l >= 0; l++) {
								if (int_grid[i - k - l][j - k - l] == 0) {
									coordinate_elem.coordinate_start = { i,j };
									coordinate_elem.coordinate_end = { i - k - l,j - k - l };
									coordinate_elem.coordinate_take = { i - k ,j - k };
									coordinate.push_back(coordinate_elem);
								}
								else {
									break;
								}
							}
						}
						if (i + k + 1 < size && j - k - 1 >= 0 && int_grid[i + k - 1][j - k + 1] == 0 && (int_grid[i + k][j - k] == 2 || int_grid[i + k][j - k] == 4)) {
							for (int l = 1; i + k + l < size && j - k - l >= 0; l++) {
								if (int_grid[i + k + l][j - k - l] == 0) {
									coordinate_elem.coordinate_start = { i,j };
									coordinate_elem.coordinate_end = { i + k + l,j - k - l };
									coordinate_elem.coordinate_take = { i + k ,j - k };
									coordinate.push_back(coordinate_elem);
								}
								else {
									break;
								}
							}
						}
					}

				}





			}
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (int_grid[i][j] == 2) {
					if (i + 2 < size && j + 2 < int_grid.size() && (int_grid[i + 1][j + 1] == 1 || int_grid[i + 1][j + 1] == 3) && int_grid[i + 2][j + 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i + 2,j + 2 };
						coordinate_elem.coordinate_take = { i + 1,j + 1 };
						coordinate.push_back(coordinate_elem);
					}
					if (j + 2 < size && i - 2 >= 0 && (int_grid[i - 1][j + 1] == 1 || int_grid[i - 1][j + 1] == 3) && int_grid[i - 2][j + 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i - 2 ,j + 2 };
						coordinate_elem.coordinate_take = { i - 1,j + 1 };
						coordinate.push_back(coordinate_elem);
					}
					if (i - 2 >= 0 && j - 2 >= 0 && (int_grid[i - 1][j - 1] == 1 || int_grid[i - 1][j - 1] == 3) && int_grid[i - 2][j - 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i - 2,j - 2 };
						coordinate_elem.coordinate_take = { i - 1,j - 1 };
						coordinate.push_back(coordinate_elem);
					}
					if (i + 2 < size && j - 2 >= 0 && (int_grid[i + 1][j - 1] == 1 || int_grid[i + 1][j - 1] == 3) && int_grid[i + 2][j - 2] == 0) {
						coordinate_elem.coordinate_start = { i,j };
						coordinate_elem.coordinate_end = { i + 2,j - 2 };
						coordinate_elem.coordinate_take = { i + 1,j - 1 };
						coordinate.push_back(coordinate_elem);
					}
				}
			}
			//return { -1,-1 };
		}
	}
	return  coordinate;

}
void  GameBoardController::checking_pat()
{
	bool found = false;
	
	for (int  i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found ; j++)
		{
			if (check_grid({ i,j }).size() != 0) {
				found = true;
				break;
			}
			else if (int_grid[i][j]  == 1 || int_grid[i][j] == 2) {

				if (is_move_checker({ i,j }, { i + 1,j + 1 })) {
					found = true;
				}
				else if (is_move_checker({ i,j }, { i - 1,j - 1 })) {
					found = true;
				}
				else if (is_move_checker({ i,j }, { i + 1,j - 1 })) {
					found = true;
				}
				else if (is_move_checker({ i,j }, { i - 1,j + 1 })) {
					found = true;
				}

			}
			else if (int_grid[i][j] == 3 || int_grid[i][j] == 4) {
				for (int k = 1; k <= 7 && !found; k++)
				{
					if (is_move_checker({ i,j }, { i + k,j + k })) {
						found = true;
					}
					else if (is_move_checker({ i,j }, { i - k,j - k })) {
						found = true;
					}
					else if (is_move_checker({ i,j }, { i + k,j - k })) {
						found = true;
					}
					else if (is_move_checker({ i,j }, { i - k,j + k })) {
						found = true;
					}
				}
			}
		}
	}
	this->check_pat = !found;

}

bool GameBoardController::is_move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end)
{
	if (coordinate_end.first  >=0 && coordinate_end.second>=0 && coordinate_end.second <8 && coordinate_end.first<8 && int_grid[coordinate_end.first][coordinate_end.second] == 0) {
		// Ïðàâèëà õîäà îáû÷íûå
		if ((coordinate_start.first + 1 == coordinate_end.first && coordinate_start.second + 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 2) {
			return true;
		}
		else if ((coordinate_start.first - 1 == coordinate_end.first && coordinate_start.second + 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 2) {
			return true;
		}
		else if (int_grid[coordinate_start.first][coordinate_start.second] == 4) {

			for (int i = 1; i <= 7; i++)
			{
				if (coordinate_start.first + i == coordinate_end.first && coordinate_start.second + i == coordinate_end.second) {
					return true;
				}
				if (coordinate_start.first - i == coordinate_end.first && coordinate_start.second + i == coordinate_end.second) {
					return true;
				}
				if (coordinate_start.first - i == coordinate_end.first && coordinate_start.second - i == coordinate_end.second) {
					return true;
				}
				if (coordinate_start.first + i == coordinate_end.first && coordinate_start.second - i == coordinate_end.second) {
					return true;
				}
			}


		}
		else if ((coordinate_start.first - 1 == coordinate_end.first && coordinate_start.second - 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 1) {
			return true;
		}
		else if ((coordinate_start.first + 1 == coordinate_end.first && coordinate_start.second - 1 == coordinate_end.second) && int_grid[coordinate_start.first][coordinate_start.second] == 1) {
			return true;
		}
		else if (int_grid[coordinate_start.first][coordinate_start.second] == 3) {

			for (int i = 1; i < 7; i++) {
				if (coordinate_start.first + i == coordinate_end.first && coordinate_start.second + i == coordinate_end.second) {
					return true;
				}
				if (coordinate_start.first - i == coordinate_end.first && coordinate_start.second + i == coordinate_end.second) {
					return true;
				}
				if (coordinate_start.first - i == coordinate_end.first && coordinate_start.second - i == coordinate_end.second) {
					return true;
				}
				if (coordinate_start.first + i == coordinate_end.first && coordinate_start.second - i == coordinate_end.second) {
					return true;
				}
			}

		}
	}
	return false;

	/*
	for (int i = 0; i < int_grid.size(); i++) {
		for (int j = 0; j < int_grid.size(); j++) {
			std::cout << int_grid[i][j] << " ";
		}
		std::cout << "" << std::endl;
	}
	*/
	
}

void GameBoardController::move_checker(const std::pair<int, int>& coordinate_start, const std::pair<int, int>& coordinate_end,int speed)
{
	int_grid[coordinate_start.first][coordinate_start.second] = 0;
	std::cout << "Cor"<<coordinate_end.first << " " << coordinate_end.second << std::endl;
	changing_checkers(current_player, coordinate_end);
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
	else if (check_pat) {
		return CheckersResult::PAT;
	}

	return CheckersResult::CONTINUE;
}


void GameBoardController::update_ai()
{
	if (show_player == ai_player) {
		coordinate_start = computer->do_move();
		coordinate_end = computer->do_move();
		vector<CaptureMove> cor = check_grid(coordinate_start);
		if ((is_move_checker(coordinate_start, coordinate_end)) && cor.size() == 0) {
			move_checker(coordinate_start, coordinate_end);
			

		}
		else {
			for (int i = 0; i < cor.size(); i++) {
				if (cor[i].coordinate_start == coordinate_start && cor[i].coordinate_end == coordinate_end) {
					move_checker(coordinate_start, coordinate_end);
					destroy_figure(cor[i].coordinate_take);
					if (check_grid(coordinate_end).size() == 0) {
						
					}
				}
				else {

				}
			}


		}
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

void GameBoardController::changing_checkers(ColorChecker current_player, const std::pair<int, int>& coordinate_end)
{
	if (coordinate_end.second == 0  && current_player == ColorChecker::White) {
			std::cout << "KK" << std::endl;
			(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->becoming_queen(assets->getTexture("queen"));
			int_grid[coordinate_end.first][coordinate_end.second] = 3;
			

	}
	if (coordinate_end.second == 7 && current_player == ColorChecker::Black) {
		std::cout << "ZZ" << std::endl;
		(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->becoming_queen(assets->getTexture("queen"));
		int_grid[coordinate_end.first][coordinate_end.second] = 4;
	}
	
	
	
}

