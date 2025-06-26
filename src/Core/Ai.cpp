#include "../include/Core/Ai.h"

sf::Vector2f Ai::do_move()
{
	sf::Vector2f position;
	position.x = rand()%8;
	position.y = rand()%8;
	return position;
}
