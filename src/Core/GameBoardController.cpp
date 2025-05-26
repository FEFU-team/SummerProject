
#include <iostream>
#include <Core/GameBoardController.h>


using namespace std;

GameBoardController::GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid)
{
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
				color_checker = (*grid_ptr)[i][j]->getChecker()->getColorChecker();
				/*
				if ((*grid_ptr)[i][j]->getColor() == sf::Color::Blue) {
					(*grid_ptr)[i][j]->setColor(sf::Color::White);
					
					
				}
				else {
					(*grid_ptr)[i][j]->setColor(sf::Color::Blue);
				}
				*/
	
				pressed_checker = true;
				break;
				
			}
			else if ((*grid_ptr)[i][j]->isPressed(position) && (*grid_ptr)[i][j]->isBeChecker() == false) {
				
				coordinate_end.first = i;
				coordinate_end.second = j;
				/* 
				if ((*grid_ptr)[i][j]->getColor() == sf::Color::Blue) {
					(*grid_ptr)[i][j]->setColor(sf::Color::White);
				}
				else {
					(*grid_ptr)[i][j]->setColor(sf::Color::Blue);
				}
				*/

				
				if (pressed_checker) {
					CaptureMove cor = check_grid();
					pair<int, int> check = { -1,-1 };
					if ((is_move_checker(color_checker)) && cor.coordinate_start==check) {
						move_checker();
					}
					else {
						if (cor.coordinate_start==coordinate_start && cor.coordinate_end == coordinate_end) {

							move_checker();
							destroy_figure(cor.coordinate_take);
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

ColorPlayer GameBoardController::getCurrentPlayer()
{
	return current_player;
}

void GameBoardController::destroy_figure(std::pair<int, int> coordinate)
{
	(*grid_ptr)[coordinate.first][coordinate.second]->delete_checker();
}

CaptureMove GameBoardController::check_grid()
{
	CaptureMove coordinate;
	coordinate.coordinate_start = { -1,-1 };
	coordinate.coordinate_end = { -1,-1 };
	if (color_checker == ColorChecker::White) {
		
		for (int i = 0; i < int_grid.size(); i++) {
			for (int j = 0; j < int_grid.size(); j++) {
				if (int_grid[i][j] == 1 && i - 2 >= 0 && j - 2 >= 0 && int_grid[i - 1][j - 1] == 2 && int_grid[i - 2][j - 2] == 0) {
					coordinate.coordinate_start = { i,j };
					coordinate.coordinate_end = { i - 2,j - 2 };
					coordinate.coordinate_take = { i - 1,j - 1 };
					return coordinate;
				}
				if (int_grid[i][j] == 1 && i + 2 < int_grid.size() && j - 2 >= 0 && int_grid[i + 1][j - 1] == 2 && int_grid[i + 2][j - 2] == 0) {
					coordinate.coordinate_start = { i,j };
					coordinate.coordinate_end = { i + 2,j - 2 };
					coordinate.coordinate_take = { i + 1,j - 1 };
					return coordinate;
				}



			}
		}
		
	}
	else {
		for (int i = 0; i < int_grid.size(); i++) {
			for (int j = 0; j < int_grid.size(); j++) {
				if (int_grid[i][j] == 2 && i+2< int_grid.size() && j + 2 < int_grid.size() && int_grid[i + 1][j + 1] == 1 && int_grid[i + 2][j + 2] == 0) {
					coordinate.coordinate_start = { i,j };
					coordinate.coordinate_end = { i + 2,j + 2 };
					coordinate.coordinate_take = { i + 1,j +  1 };
					return coordinate;
				}
				if (int_grid[i][j] == 2 && j + 2 < int_grid.size() && i - 2  >= 0 && int_grid[i - 1][j + 1] == 1 && int_grid[i-2][j+2] == 0) {
					coordinate.coordinate_start = { i,j };
					coordinate.coordinate_end = { i-2 ,j + 2 };
					coordinate.coordinate_take = { i-1,j +1 };
					return coordinate;
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

