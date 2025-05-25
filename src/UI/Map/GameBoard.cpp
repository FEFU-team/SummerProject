
#include <UI/Map/GameBoard.h>
#include <iostream>

void GameBoard::draw(sf::RenderTarget* window,float delta_time) {
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			grid[i][j]->draw(window);
			if (grid[i][j]->isBeChecker()) {
				grid[i][j]->getChecker()->draw(window);
			}
		}
		
	}//
	
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			if (grid[i][j]->isBeChecker() && (grid[i][j]->getChecker()->is_move())) {
				grid[i][j]->getChecker()->update(delta_time);
				grid[i][j]->getChecker()->draw(window);
			}



		}

	}
}
void GameBoard::draw(sf::RenderTarget* window) {
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			grid[i][j]->draw(window);



		}

	}
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++) {
			if (grid[i][j]->isBeChecker()) {
				grid[i][j]->getChecker()->draw(window);
			}



		}

	}

}
GameBoard::GameBoard(sf::Vector2f positions ) {
	position = positions;
	int size_h = HEIGHT;
	int size_w = WIDTH;
	for (int i = position.x, h = 0; h < size_h; i++, h++) {
		float posX = (100 + 1) * i;
		std::vector<std::unique_ptr<Cell>> line;
		for (int j = position.y, w = 0; w < size_w; j++, w++) {
			line.reserve(size_w); // �������� ����� ������ �� ������ �������
			float posY = (100 + 1) * j;
			if ((h+w)%2 == 0) {
				line.emplace_back(// �������� ����� ������ ����� ��� ����������� 
					std::make_unique<Cell>(sf::Vector2f(posX, posY), sf::Color::White)
				);
			}
			else {

				line.emplace_back(// �������� ����� ������ ����� ��� ����������� 
					std::make_unique<Cell>(sf::Vector2f(posX, posY), sf::Color::Black)
				);
			}
			//����������� ����
			if (w < 3) {
				if ((h + w) % 2 == 1) {

					//line[w]->setChecker(sf::Color::White);


				}
				else {
					// ���� �����
					line[w]->setChecker(sf::Color::Yellow);


				}
			}
			if (w > 4) {
				if ((h + w) % 2 == 1) {
					// ���� �����
					line[w]->setChecker(sf::Color::Green);


				}
				else {

					//line[w]->setChecker(sf::Color::Black);


				}
			}
			
			
			
		}
		
		grid.emplace_back(std::move(line));//  move ���������� ������ line .� �� �������� ���.
	}
}
void GameBoard::setPosition(sf::Vector2f new_position)
{
	this->position = new_position;
}