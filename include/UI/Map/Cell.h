#pragma once
#include "../include/UI/Button.h"
#include <string>
//������ ����
class Cell : public Button
{
	// ������ ����� . ����� ��� �������
public:
	//����������� � ����������� ������� � �����
	Cell(sf::Vector2f positions,sf::Color cell_color = sf::Color::White);
	Cell();
private:

};
