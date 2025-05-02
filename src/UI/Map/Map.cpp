
#include <UI/Map/Map.h>
#include <iostream>

void Map::Draw(sf::RenderTarget* window) {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			grid[i][j].Draw(window);
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
			line.push_back(Cell({ posX, posY }));
		}
		grid.push_back(line);
	}
}