#pragma once
#include "../include/UI/Button.h"
#include <string>
//Ячейка поля
class Cell : public Button
{
	// объект шашки . дамка или обычная
public:
	//Конструктор с параметрами позиции и цвета
	Cell(sf::Vector2f positions,sf::Color cell_color = sf::Color::White);
	Cell();
private:

};
