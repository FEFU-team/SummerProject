#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
using namespace std;
class Map: public Elem {
private:
	 const  int HEIGHT = 10;
	 const  int WIDTH = 10;
	 std::vector<std::vector<Cell>> grid;
public:
	
	void draw(sf::RenderTarget* window) override;
	Map(sf::Vector2f positions = {0,0});
};