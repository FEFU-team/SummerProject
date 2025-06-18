#pragma once
#include <SFML/Graphics.hpp>
class SizeBox {
public:
	sf::FloatRect getGlobalBounds(); 
	sf::FloatRect getLocalBounds();
	sf::Vector2f getCenter();
	SizeBox(sf::Vector2f position,sf::Vector2f size = { 1,1 });
private:
	sf::RectangleShape shape;
	sf::Vector2f size;
};