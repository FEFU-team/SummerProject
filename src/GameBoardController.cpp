#include <GameBoardController.h>
#include <iostream>
GameBoardController::GameBoardController(std::vector<std::vector<std::unique_ptr<Cell>>>* grid)
{
	//Создание целочисленной матрицы . где 1 это есть шашка . 0 это нет шашки
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

void GameBoardController::update_input(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, sf::Vector2f position)
{
	for (int i = 0; i < grid->size(); i++) {
		for (int j= 0; j < grid->size(); j++) {
			if ((*grid)[i][j]->isPressed(position) && (*grid)[i][j]->isBeChecker()) {

				if ((*grid)[i][j]->getColor() == sf::Color::Blue) {
					(*grid)[i][j]->setColor(sf::Color::White);
				}
				else {
					(*grid)[i][j]->setColor(sf::Color::Blue);
				}
			}
			else if ((*grid)[i][j]->isPressed(position)) {

				if ((*grid)[i][j]->getColor() == sf::Color::Blue) {
					(*grid)[i][j]->setColor(sf::Color::White);
				}
				else {
					(*grid)[i][j]->setColor(sf::Color::Blue);
				}
			}
			else {
				
			}
		}
	}
}

bool GameBoardController::is_move_checker(std::pair<int, int> сordinat_begin, std::pair<int, int> сordinat_end)
{

	return false;
}

