
#include <iostream>
#include <Core/GameBoardController.h>

using namespace std;

GameBoardController::GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid)
{
	this->grid_ptr = grid;
	//Создание целочисленной матрицы . где 1 это есть шашка . 0 это нет шашки
	for (int i = 0; i < grid->size(); i++) {
		vector<int> line(grid->size(), 0);
		for (int j = 0; j < grid->size(); j++) {
			if((*grid)[i][j]->isBeChecker()){

				line[j]=1;
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
				coordinate_begin.first = i;
				coordinate_begin.second = j;
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
				if (pressed_checker && is_move_checker(color_checker)) {
					move_checker();
				}
				pressed_checker = false;
				break;
			}
			else{
			}
		}
	}
}

void GameBoardController::destroy_figure(std::pair<int, int> coordinate)
{
	(*grid_ptr)[coordinate.first][coordinate.second]->delete_checker();
}

void GameBoardController::update_int_grid()
{

}

bool GameBoardController::is_move_checker(ColorChecker color_checker)
{
	// Правила хода обычные
	if ((coordinate_begin.first + 1 == coordinate_end.first && coordinate_begin.second + 1 == coordinate_end.second)&&color_checker == ColorChecker::Black) {
		return true;
	}
	else if ((coordinate_begin.first - 1 == coordinate_end.first && coordinate_begin.second - 1 == coordinate_end.second) && color_checker == ColorChecker::White) {
		return true;
	}
	else if ((coordinate_begin.first - 1 == coordinate_end.first && coordinate_begin.second + 1 == coordinate_end.second) && color_checker == ColorChecker::Black) {
		return true;
	}
	else if ((coordinate_begin.first + 1 == coordinate_end.first && coordinate_begin.second - 1 == coordinate_end.second) && color_checker == ColorChecker::White) {
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

void GameBoardController::move_checker()
{
	int_grid[coordinate_begin.first][coordinate_begin.second] = 0;
	int_grid[coordinate_end.first][coordinate_end.second] = 1;
	// Получаем владение от исходной ячейки
	auto checker = (*grid_ptr)[coordinate_begin.first][coordinate_begin.second]->releaseChecker();
	// Анимация перемещения
	checker->start_move((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());

	// Передаем в целевую ячейку
	(*grid_ptr)[coordinate_end.first][coordinate_end.second]->transferChecker(std::move(checker));
	
	// Передаем координаты для новой пешки
	//(*grid_ptr)[coordinate_end.first][coordinate_end.second]->getChecker()->setPosition((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());
}

