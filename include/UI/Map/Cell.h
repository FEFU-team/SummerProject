#pragma once
#include "../include/UI/Button.h"
#include <string>
#include <UI/Checkers/Checker.h>
//������ ����
class Cell : public Button
{
	// ������ ����� . ����� ��� �������
public:
	Checker* checker;
	 bool is_be_checker = false;
	//����������� � ����������� ������� � �����
	Cell(sf::Vector2f positions,sf::Color cell_color = sf::Color::White, Checker* checker = nullptr);
	Cell();
private:

};
