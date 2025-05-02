
#include <UI/Map/Map.h>
#include <iostream>

void Map::draw(sf::RenderTarget* window) {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			grid[i][j].draw(window);
			if (grid[i][j].is_be_checker) {
				grid[i][j].checker->draw(window);
			}
		}
		
	}
}
Map::Map(sf::Vector2f positions ) {
	position = positions;
	int size_h = HEIGHT;
	int size_w = WIDTH;
	for (int i = position.x, h = 0; h < size_h; i++, h++) {
		float posX = (50 + 1) * i;
		vector<Cell> line;
		for (int j = position.y, w = 0; w < size_w; j++, w++) {
			float posY = (50 + 1) * j;
			if ((h+w)%2 == 0) {
				line.push_back(Cell({ posX, posY },sf::Color::White));
			}
			else {
				Checker* ch = new Checker;
				line.push_back(Cell({ posX, posY }, sf::Color::Black,ch));
				
			}
			
		}
		grid.push_back(line);
	}
}