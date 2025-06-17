#pragma once
#include "../include/UI//Buttons/Button.h"
#include <string>
#include <memory>
#include "../include/UI/Checkers/Checker.h"
//Ячейка поля
class Cell : public Button
{
public:
	// Уничтожение фигуры
	void delete_checker();
	// Получение центра в ячейки
	sf::Vector2f getCenter();
	// Получение прав на указатель шашки
	void transferChecker(std::unique_ptr<Checker> ptr);
	// Передача прав на указатель шашки
	std::unique_ptr<Checker> releaseChecker();
	// Установка фигуры в ячейку
	void create_figures(sf::Color color,sf::Texture texture);
	// Получение обычного указателя
	Checker* getChecker();
	//Есть ли шапка в ячейке
	bool isBeChecker();
	void set_active();
	bool is_active();
	//Конструктор с параметрами позиции и цвета
	Cell(sf::Vector2f position,sf::Color cell_color = sf::Color::White);
	Cell();
private:
	sf::Vector2f center;
	std::unique_ptr<Checker> checker_ptr;
	bool is_be_checker = false;
	bool active = false;
};
