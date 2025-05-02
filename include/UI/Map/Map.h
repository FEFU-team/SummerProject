#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
using namespace std;
class Map {
public:
	void Draw(sf::RenderTarget* window);
	Map(); 
	std::vector<std::vector<Cell>> grid;
};