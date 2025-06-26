#include "../include/Core/Ai.h"

std::pair<int,int> Ai::do_move()
{
	sf::Vector2f position;
	position.x = rand()%8;
	position.y = rand()%8;
	return {position.x,position.y};
}
