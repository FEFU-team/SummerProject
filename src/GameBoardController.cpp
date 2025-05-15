#include <GameBoardController.h>
#include <iostream>
GameBoardController::GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid)
{
	this->grid_ptr = grid;
	//—оздание целочисленной матрицы . где 1 это есть шашка . 0 это нет шашки
	for (int i = 0; i < grid->size(); i++) {
		std::vector<int> line(grid->size(), 0);
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
				if ((*grid_ptr)[i][j]->getColor() == sf::Color::Blue) {
					(*grid_ptr)[i][j]->setColor(sf::Color::White);
				}
				else {
					(*grid_ptr)[i][j]->setColor(sf::Color::Blue);
				}
				pressed_checker = true;
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
				if (pressed_checker) {
					move_checker();
				}
				pressed_checker = false;
				break;
			}
			else {
				
			}
		}
	}
}

void GameBoardController::update_animation(float delta_time)
{
	for (int i = 0; i < grid_ptr->size(); i++) {
		for (int j = 0; j < grid_ptr->size(); j++) {
			if ((*grid_ptr)[i][j]->isBeChecker()) {
				(*grid_ptr)[i][j]->getChecker()->update(delta_time);
			}
		}
	}
}

void GameBoardController::update_int_grid()
{

}

bool GameBoardController::is_move_checker()
{

	return true;
}

void GameBoardController::move_checker()
{
	// ѕолучаем владение от исходной €чейки
	auto checker = (*grid_ptr)[coordinate_begin.first][coordinate_begin.second]->releaseChecker();
	// јнимаци€ перемещени€
	checker->start_move((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());

	// ѕередаем в целевую €чейку
	(*grid_ptr)[coordinate_end.first][coordinate_end.second]->transferChecker(std::move(checker));
	
	// ѕередаем координаты дл€ новой пешки
	//(*grid_ptr)[coordinate_end.first][coordinate_end.second]->getChecker()->setPosition((*grid_ptr)[coordinate_end.first][coordinate_end.second]->getPosition());
}

