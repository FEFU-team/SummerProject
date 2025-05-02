
#include <UI/Map/Map.h>
#include <iostream>

void Map::draw(sf::RenderTarget* window) {
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			grid[i][j]->draw(window);
			//if (grid[i][j].isBeChecker()) {
				//grid[i][j].checker->draw(window);
			//}

		}
		
	}
}
Map::Map(sf::Vector2f positions ) {
	position = positions;
	int size_h = HEIGHT;
	int size_w = WIDTH;
	for (int i = position.x, h = 0; h < size_h; i++, h++) {
		float posX = (50 + 1) * i;
		std::vector<std::unique_ptr<Cell>> line;
		for (int j = position.y, w = 0; w < size_w; j++, w++) {
			line.reserve(size_w); // Выделяет сразу память на размер вектора
			float posY = (50 + 1) * j;
			if ((h+w)%2 == 0) {
				line.emplace_back(// Добавляя новый объект сразу без копирование 
					std::make_unique<Cell>(sf::Vector2f(posX, posY), sf::Color::White)
				);
			}
			else {

				line.emplace_back(
					std::make_unique<Cell>(sf::Vector2f(posX, posY), sf::Color::Black)
				);
				
			}
			
		}
		grid.emplace_back(std::move(line));//  move перемещает вектор line .а не копирует его.
	}
}