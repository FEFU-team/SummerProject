#pragma once
#include "../include/UI/Button.h"
#include <string>
#include "../include/UI/Checkers/Checker.h"
//������ ����
class Cell : public Button
{
	// ������ ����� . ����� ��� �������
public:
	void setChecker();
	Checker* checker;
	bool is_be_checker = false;
	//����������� � ����������� ������� � �����
	Cell(sf::Vector2f positions,sf::Color cell_color = sf::Color::White, Checker* checker = nullptr);
	Cell();
private:
	
	
};
