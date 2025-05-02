#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
using namespace std;
class Map:Element {
private:
	// Длина поля
	 const  int HEIGHT = 8;
	// Ширина поля
	 const  int WIDTH = 8;
	// Сетка игрового поля
	 std::vector<std::vector<std::unique_ptr<Cell>>> grid;
public:
	//Функция отрисовки Поля
	void draw(sf::RenderTarget* window) override;
	Map(sf::Vector2f positions = {0,0});
};