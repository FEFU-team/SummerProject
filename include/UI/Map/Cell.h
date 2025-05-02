#pragma once
#include "../include/UI/Button.h"
#include <string>
#include "../include/UI/Checkers/Checker.h"
//������ ����
class Cell : public Button
{
public:
	void setChecker(sf::Color checker_color);
	Checker* getChecker();
	bool isBeChecker();
	//����������� � ����������� ������� � �����
	Cell(sf::Vector2f positions,sf::Color cell_color = sf::Color::White);
	Cell();
private:
	Checker* checker = nullptr;
	bool is_be_checker = false;
};
