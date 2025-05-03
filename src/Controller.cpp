#include <Controller.h>
#include <iostream>
void Controller::update()
{
	
}
void Controller::changeColor(Cell* cell)
{
	if (cell->getColor() == sf::Color::Yellow) {
		cell->setColor(sf::Color::Black);
	}
	else {
		cell->setColor(sf::Color::Yellow);
	}
	
	std::cout << "Color change" <<std:: endl;

}
Controller::Controller()
{

}