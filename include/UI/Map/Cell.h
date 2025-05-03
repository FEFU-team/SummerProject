#pragma once
#include "../include/UI/Button.h"
#include <string>
#include <memory>
#include "../include/UI/Checkers/Checker.h"
//Ячейка поля
class Cell : public Button
{
public:
	void setChecker(sf::Color color);
	Checker* getChecker();
	bool isBeChecker();
	//Конструктор с параметрами позиции и цвета
	Cell(sf::Vector2f position,sf::Color cell_color = sf::Color::White);
	Cell();
private:
	std::unique_ptr<Checker> checker_ptr;
	bool is_be_checker = false;
};
