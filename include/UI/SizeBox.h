#pragma once
#include <SFML/Graphics.hpp>
class SizeBox {
public:
	sf::FloatRect getGlobalBounds(); 
	sf::FloatRect getLocalBounds();
	SizeBox(sf::Vector2f position,sf::Vector2f size);
private:
	sf::RectangleShape shape;
	sf::Vector2f size;
};