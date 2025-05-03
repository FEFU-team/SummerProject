#include <Controller.h>
#include <iostream>
void Controller::updateEvent(sf::Event)
{

}
void Controller::changeColor(Cell* cell)
{
	cell->setColor(sf::Color::Yellow);
	std::cout << "Color change" <<std:: endl;

}
Controller::Controller()
{

}