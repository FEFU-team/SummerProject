#pragma once
#include "../include/UI/Button.h"
#include <string>
#include <memory>
#include "../include/UI/Checkers/Checker.h"
//Ячейка поля
class Cell : public Button
{
public:
	// Получение центра в ячейки
	sf::Vector2f getCenter();
	void transferChecker(std::unique_ptr<Checker> ptr);
	std::unique_ptr<Checker> releaseChecker();
	void setChecker(sf::Color color);
	Checker* getChecker();
	//Есть ли шашпка в ячейке
	bool isBeChecker();
	//Конструктор с параметрами позиции и цвета
	Cell(sf::Vector2f position,sf::Color cell_color = sf::Color::White);
	Cell();
private:
	sf::Vector2f center;
	std::unique_ptr<Checker> checker_ptr;
	bool is_be_checker = false;
};
