#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
using namespace std;
class Map:Elem {
private:
	 const  int HEIGHT = 10;
	 const  int WIDTH = 10;
public:
	
	void Draw(sf::RenderTarget* window) override;
	Map(sf::Vector2f positions = {0,0});
	std::vector<std::vector<Cell>> grid;
};