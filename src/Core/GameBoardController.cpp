
#include <iostream>
#include <Core/GameBoardController.h>



using namespace std;

GameBoardController::GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, AssetManager* assets)
{
	this->assets = assets;
	this->grid_ptr = grid;
	//Создание целочисленной матрицы . где 1 . 0 это нет шашки
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
				coordinate_start.first = i;
				coordinate_start.second = j;
				current_player = (*grid_ptr)[i][j]->getChecker()->getColorChecker();
				// Отработка двойного нажатия
				if ((*grid_ptr)[i][j]->isBeChecker()) {  
					if ((*grid_ptr)[i][j]->getChecker()->is_active()) {

						(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker1"), false);
						pressed_checker = false;
					}
					else {
						(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker_active"), true);
						pressed_checker = true;
					}
				}
				break;
				
			}
			else if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() && !(*grid_ptr)[i][j]->getChecker()->is_move()) {
				// Снимаем выделение с прошлой шашки
				(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("checker1"), false);
				// Выделяем шашку  текущию
				(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker_active"), true);
				coordinate_start.first = i;
				coordinate_start.second = j;
				if (current_player != (*grid_ptr)[i][j]->getChecker()->getColorChecker()) {
					current_player = (*grid_ptr)[i][j]->getChecker()->getColorChecker();
				}
				
				break;
			}
			else if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() == false ) {
				coordinate_end.first = i;
				coordinate_end.second = j;
				// Снимаем выделение с шашки
				if ((*grid_ptr)[coordinate_start.first][coordinate_start.second]->isBeChecker() && !(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->is_move()) {
					(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("checker1"), false);
				}
				
				if (pressed_checker && current_player != previous_player) {
					vector<CaptureMove> cor = check_grid(current_player);
					(*grid_ptr)[coordinate_start.first][coordinate_start.second]->getChecker()->update_texture(assets->getTexture("checker1"), false);
					update_GameState();
					//cout << cor.coordinate_take.first << endl;
					//cout << cor.coordinate_take.second << endl;
					if ((is_move_checker(current_player)) && (cor.size() == 0)) {
						move_checker();
						cout << "S" << endl;
						previous_player = current_player;

					}
					else {
						for (int i = 0; i < cor.size(); i++) {
							if (cor[i].coordinate_start == coordinate_start && cor[i].coordinate_end == coordinate_end) {
								move_checker();
								cout << "D" << endl;
								int_grid[cor[i].coordinate_take.first][cor[i].coordinate_take.second] = 0;
								destroy_figure(cor[i].coordinate_take);
								if (check_grid(current_player).size() == 0) {
									previous_player = current_player;
									//(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker1"), false);
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
			else {

			}
		}
	}
}

ColorChecker GameBoardController::getCurrentPlayer()
{
	// Странности 
	return show_player;
}

void GameBoardController::destroy_figure(std::pair<int, int> coordinate)
{
	(*grid_ptr)[coordinate.first][coordinate.second]->delete_checker();
}

vector<CaptureMove> GameBoardController::check_grid(ColorChecker current_player)
{
	vector<CaptureMove> coordinate;
	CaptureMove coordinate_elem;
	if (int_grid[coordinate_start.first][coordinate_start.second] == 1 || int_grid[coordinate_start.first][coordinate_start.second] == 3) {
		
		for (int i = 0; i < int_grid.size(); i++) {
			for (int j = 0; j < int_grid.size(); j++) {
				if (int_grid[i][j] == 1 && i - 2 >= 0 && j - 2 >= 0 && int_grid[i - 1][j - 1] == 2 && int_grid[i - 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2,j - 2 };
					coordinate_elem.coordinate_take = { i - 1,j - 1 };
					coordinate.push_back(coordinate_elem);
				}
				if (int_grid[i][j] == 1 && i + 2 < int_grid.size() && j - 2 >= 0 && int_grid[i + 1][j - 1] == 2 && int_grid[i + 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j - 2 };
					coordinate_elem.coordinate_take = { i + 1,j - 1 };
					coordinate.push_back(coordinate_elem);
				}
				if (int_grid[i][j] == 1 && i + 2 < int_grid.size() && j + 2 < int_grid.size() && int_grid[i + 1][j + 1] == 2 && int_grid[i + 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j + 2 };
					coordinate_elem.coordinate_take = { i + 1,j + 1 };
					coordinate.push_back(coordinate_elem);
				}
				if (int_grid[i][j] == 1 && j + 2 < int_grid.size() && i - 2 >= 0 && int_grid[i - 1][j + 1] == 2 && int_grid[i - 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2 ,j + 2 };
					coordinate_elem.coordinate_take = { i - 1,j + 1 };
					coordinate.push_back(coordinate_elem);
				}



			}
		}
		

	}
	else {
		for (int i = 0; i < int_grid.size(); i++) {
			for (int j = 0; j < int_grid.size(); j++) {
				if (int_grid[i][j] == 2 && i + 2 < int_grid.size() && j + 2 < int_grid.size() && int_grid[i + 1][j + 1] == 1 && int_grid[i + 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j + 2 };
					coordinate_elem.coordinate_take = { i + 1,j + 1 };
					coordinate.push_back(coordinate_elem);
				}
				if (int_grid[i][j] == 2 && j + 2 < int_grid.size() && i - 2 >= 0 && int_grid[i - 1][j + 1] == 1 && int_grid[i - 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2 ,j + 2 };
					coordinate_elem.coordinate_take = { i - 1,j + 1 };
					coordinate.push_back(coordinate_elem);
				}

				if (int_grid[i][j] == 2 && i - 2 >= 0 && j - 2 >= 0 && int_grid[i - 1][j - 1] == 1 && int_grid[i - 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i - 2,j - 2 };
					coordinate_elem.coordinate_take = { i - 1,j - 1 };
					coordinate.push_back(coordinate_elem);
				}
				if (int_grid[i][j] == 2 && i + 2 < int_grid.size() && j - 2 >= 0 && int_grid[i + 1][j - 1] == 1 && int_grid[i + 2][j - 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j - 2 };
					coordinate_elem.coordinate_take = { i + 1,j - 1 };
					coordinate.push_back(coordinate_elem);
				}



			}
		}
		
	}
	return coordinate;
	//return { -1,-1 };
}



bool GameBoardController::is_move_checker(ColorChecker color_checker)
{
	
	// Правила хода обычные
	if ((coordinate_start.first + 1 == coordinate_end.first && coordinate_start.second + 1 == coordinate_end.second)&& int_grid[coordinate_start.first][coordinate_start.second] == 2) {
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

void GameBoardController::move_checker(int speed)
{
	int_grid[coordinate_start.first][coordinate_start.second] = 0;
	std::cout << "Cor"<<coordinate_end.first << " " << coordinate_end.second << std::endl;
	changing_checkers(current_player, coordinate_end);
	// Получаем владение от исходной ячейки
	auto checker = (*grid_ptr)[coordinate_start.first][coordinate_start.second]->releaseChecker();
	if (checker->getColorChecker() == ColorChecker::Black && !checker->is_queen()) {
		show_player = ColorChecker::White;
		int_grid[coordinate_end.first][coordinate_end.second] = 2;
	}
	else if (checker->getColorChecker() == ColorChecker::Black && checker->is_queen()) {
		int_grid[coordinate_end.first][coordinate_end.second] = 4;
		show_player = ColorChecker::White;
	}
	else {
		show_player = ColorChecker::Black;
		if (checker->is_queen()) {
			int_grid[coordinate_end.first][coordinate_end.second] = 3;
		}
		else {
			int_grid[coordinate_end.first][coordinate_end.second] = 1;
		}
		
	}
	
	// Анимация перемещения
	checker->start_move((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());

	// Передаем в целевую ячейку
	(*grid_ptr)[coordinate_end.first][coordinate_end.second]->transferChecker(std::move(checker));
	
	// Передаем координаты для новой пешки
	//(*grid_ptr)[coordinate_end.first][coordinate_end.second]->getChecker()->setPosition((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());
}

void GameBoardController::update_GameState()
{
	int black_checker_count = 0;
	int white_checker_count = 0;

	for (int i = 0; i < int_grid.size(); i++) {
		for (int j = 0; j < int_grid.size(); j++) {
			if (int_grid[i][j] == 1) {
				white_checker_count++;
			}
			else if (int_grid[i][j] == 2) {
				black_checker_count++;
			}
			else {
				// TODO
			}
		}
	}

	if (white_checker_count == 0 && black_checker_count != 0) {
		gameBoardState = CheckersResult::WINBLACK;
	}

	if (white_checker_count != 0 && black_checker_count == 0) {
		gameBoardState = CheckersResult::WINWHITE;
	}

	// ситуацию для пата реализовать

	//cout << "Count white checker: " << WhiteCheckerCount << endl;
	//cout << "Count black checker: " << BlackCheckerCount << endl;

	//return CheckersResult::CONTINUE;
}

void GameBoardController::changing_checkers(ColorChecker current_player, const std::pair<int, int>& coordinate_end)
{
	if (coordinate_end.second == 0  && current_player == ColorChecker::White) {

		//int_grid[coordinate_end.first][coordinate_end.second]
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

