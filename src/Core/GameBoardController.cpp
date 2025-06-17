
#include <iostream>
#include <Core/GameBoardController.h>
#include <set>
#include <Core/AssetManager.h>


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

			if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() && pressed_checker == false) {
				coordinate_start.first = i;
				coordinate_start.second = j;
				current_player = (*grid_ptr)[i][j]->getChecker()->getColorChecker();
				(*grid_ptr)[i][j]->getChecker()->update_texture(assets->getTexture("checker_active"));
				if ((*grid_ptr)[i][j]->getColor() == sf::Color::Blue) {
					(*grid_ptr)[i][j]->setColor(sf::Color::White);
					
					
				}
				else {
					(*grid_ptr)[i][j]->setColor(sf::Color::Blue);
				}
				
	
				pressed_checker = true;
				// test gordey
				
				
				break;
				
			}
			else if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() == false) {
				
				coordinate_end.first = i;
				coordinate_end.second = j;
				
				if ((*grid_ptr)[i][j]->getColor() == sf::Color::Blue) {
					(*grid_ptr)[i][j]->setColor(sf::Color::White);
				}
				else {
					(*grid_ptr)[i][j]->setColor(sf::Color::Blue);
				}
				

				
				if (pressed_checker&&current_player!=previous_player) {
					vector<CaptureMove> cor = check_grid(current_player);
					update_GameState();
					//cout << cor.coordinate_take.first << endl;
					//cout << cor.coordinate_take.second << endl;
					if ((is_move_checker(current_player)) &&(cor.size() == 0)) {
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
								}


							}
						}
						
						
					}


				}
				pressed_checker = false;
				
				break;
			}
			else{
			}
		}
	}
}

ColorChecker GameBoardController::getCurrentPlayer()
{
	return current_player;
}

void GameBoardController::destroy_figure(std::pair<int, int> coordinate)
{
	(*grid_ptr)[coordinate.first][coordinate.second]->delete_checker();
}

vector<CaptureMove> GameBoardController::check_grid(ColorChecker current_player)
{
	vector<CaptureMove> coordinate;
	CaptureMove coordinate_elem;
	if (current_player == ColorChecker::White) {
		
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



			}
		}
		for (int i = 0; i < int_grid.size(); i++) {
			for (int j = 0; j < int_grid.size(); j++) {
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
				if (int_grid[i][j] == 2 && i+2< int_grid.size() && j + 2 < int_grid.size() && int_grid[i + 1][j + 1] == 1 && int_grid[i + 2][j + 2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i + 2,j + 2 };
					coordinate_elem.coordinate_take = { i + 1,j +  1 };
					coordinate.push_back(coordinate_elem);
				}
				if (int_grid[i][j] == 2 && j + 2 < int_grid.size() && i - 2  >= 0 && int_grid[i - 1][j + 1] == 1 && int_grid[i-2][j+2] == 0) {
					coordinate_elem.coordinate_start = { i,j };
					coordinate_elem.coordinate_end = { i-2 ,j + 2 };
					coordinate_elem.coordinate_take = { i-1,j +1 };
					coordinate.push_back(coordinate_elem);
				}

				



			}
		}
		for (int i = 0; i < int_grid.size(); i++) {
			for (int j = 0; j < int_grid.size(); j++) {
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
	if ((coordinate_start.first + 1 == coordinate_end.first && coordinate_start.second + 1 == coordinate_end.second)&&color_checker == ColorChecker::Black) {
		return true;
	}
	else if ((coordinate_start.first - 1 == coordinate_end.first && coordinate_start.second + 1 == coordinate_end.second) && color_checker == ColorChecker::Black) {
		return true;
	}
	else if ((coordinate_start.first - 1 == coordinate_end.first && coordinate_start.second - 1 == coordinate_end.second) && color_checker == ColorChecker::White) {
		return true;
	}
	else if ((coordinate_start.first + 1 == coordinate_end.first && coordinate_start.second - 1 == coordinate_end.second) && color_checker == ColorChecker::White) {
		return true;
	}
	else {
		return false;
	}
	/*
	for (int i = 0; i < int_grid.size(); i++) {
		for (int j = 0; j < int_grid.size(); j++) {
			std::cout << int_grid[i][j] << " ";
		}
		std::cout << "" << std::endl;
	}
	*/
	return true;
}

void GameBoardController::move_checker(int speed)
{
	int_grid[coordinate_start.first][coordinate_start.second] = 0;
	
	// Получаем владение от исходной ячейки
	auto checker = (*grid_ptr)[coordinate_start.first][coordinate_start.second]->releaseChecker();
	if (checker->getColorChecker() == ColorChecker::Black) {
		int_grid[coordinate_end.first][coordinate_end.second] = 2;
	}
	else {
		int_grid[coordinate_end.first][coordinate_end.second] = 1;
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
	int BlackCheckerCount = 0;
	int WhiteCheckerCount = 0;

	for (int i = 0; i < int_grid.size(); i++) {
		for (int j = 0; j < int_grid.size(); j++) {
			if (int_grid[i][j] == 1) {
				WhiteCheckerCount++;
			}
			else if (int_grid[i][j] == 2) {
				BlackCheckerCount++;
			}
			else {
				// TODO
			}
		}
	}

	if (WhiteCheckerCount == 0 && BlackCheckerCount != 0) {
		gameBoardState = CheckersResult::WINBLACK;
	}

	if (WhiteCheckerCount != 0 && BlackCheckerCount == 0) {
		gameBoardState = CheckersResult::WINWHITE;
	}

	// ситуацию для пата реализовать

	cout << "Count white checker: " << WhiteCheckerCount << endl;
	cout << "Count black checker: " << BlackCheckerCount << endl;

	//return CheckersResult::CONTINUE;
}

