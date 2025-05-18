#pragma once
#include "../include/UI//Buttons/Button.h"
#include <string>
#include <memory>
#include "../include/UI/Checkers/Checker.h"
//������ ����
class Cell : public Button
{
public:
	// ��������� ������ � ������
	sf::Vector2f getCenter();
	// ��������� ���� �� ��������� �����
	void transferChecker(std::unique_ptr<Checker> ptr);
	// �������� ���� �� ��������� �����
	std::unique_ptr<Checker> releaseChecker();
	// ��������� ������ � ������
	void setChecker(sf::Color color);
	// ��������� �������� ���������
	Checker* getChecker();
	//���� �� ����� � ������
	bool isBeChecker();
	//����������� � ����������� ������� � �����
	Cell(sf::Vector2f position,sf::Color cell_color = sf::Color::White);
	Cell();
private:
	sf::Vector2f center;
	std::unique_ptr<Checker> checker_ptr;
	bool is_be_checker = false;
};
