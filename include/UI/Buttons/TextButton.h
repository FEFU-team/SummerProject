#pragma once
#include "../include/UI//Buttons/Button.h"
#include <SFML/Graphics.hpp>
class TextButton : public Button {
public:
	TextButton(sf::Vector2f position,sf::Color color = sf::Color::Cyan);
private:
	sf::RectangleShape shape;
	
};
