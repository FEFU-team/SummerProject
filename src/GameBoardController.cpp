#include <GameBoardController.h>
#include <iostream>
GameBoardController::GameBoardController()
{

}

void GameBoardController::update_input(std::vector<std::vector<std::unique_ptr<Cell>>>* grid, sf::Vector2f position)
{
	for (int i = 0; i < grid->size(); i++) {
		for (int j= 0; j < grid->size(); j++) {
			if ((*grid)[i][j]->isPressed(position) && (*grid)[i][j]->isBeChecker()) {

				checker_pressed = true;
				if ((*grid)[i][j]->getColor() == sf::Color::Blue) {
					(*grid)[i][j]->setColor(sf::Color::White);
				}
				else {
					(*grid)[i][j]->setColor(sf::Color::Blue);
				}
				std::cout << "button" << std::endl;
			}
			else if ((*grid)[i][j]->isPressed(position)) {
				cell_pressed = true;
				if ((*grid)[i][j]->getColor() == sf::Color::Blue) {
					(*grid)[i][j]->setColor(sf::Color::White);
				}
				else {
					(*grid)[i][j]->setColor(sf::Color::Blue);
				}
			}
			else {
				checker_pressed = false;
				cell_pressed = false;
			}
		}
	}
}
