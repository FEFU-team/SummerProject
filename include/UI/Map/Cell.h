#pragma once
#include "../include/UI/Button.h"
#include <string>
#include <UI/Checkers/Checker.h>
//Ячейка поля
class Cell : public Button
{
	// объект шашки . дамка или обычная
public:
	Checker* checker;
	 bool is_be_checker = false;
	//Конструктор с параметрами позиции и цвета
	Cell(sf::Vector2f positions,sf::Color cell_color = sf::Color::White, Checker* checker = nullptr);
	Cell();
private:

};
