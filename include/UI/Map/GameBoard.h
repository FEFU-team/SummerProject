#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
using namespace std;
class GameBoard: public Widget {
public:
	void draw(sf::RenderTarget* window) override;
	//Функция отрисовки Поля
	void draw(sf::RenderTarget* window, float delta_time);
	GameBoard(sf::Vector2f positions);
	// Сетка игрового поля
	std::vector<std::vector<std::unique_ptr<Cell>>> grid;
	// Унаследовано через Widget
	void setPosition(sf::Vector2f new_position) override;
private:
	// Длина поля
	const  int HEIGHT = 8;
	// Ширина поля
	const  int WIDTH = 8;

};