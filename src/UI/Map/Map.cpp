
#include <UI/Map/Map.h>
#include <iostream>

void Map::Draw(sf::RenderTarget* window) {
	for (int i = 0; i < 20; i++)
	{
		grid[i].Draw(window);
	}
}
Map::Map() {
    for (int i = 0; i < 10; i++) {
		float posX = (50+1) * i;
		for (int j = 0; j < 10; j++) {
			float posY = (50 + 1) * j;
			 grid.push_back(Cell({ posX,posY}));
		}
       
    }
}