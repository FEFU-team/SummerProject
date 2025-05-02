
#include <iostream>
#include <SFML/Graphics.hpp>
#include <UI/Button.h>
unsigned int Button::getKey()
{
	return key;
}

void Button::Pressed()
{
	std::cout << "Hello" << std::endl;
}

bool Button::IsPressed(sf::Vector2f mouse_position_f)
{
	return shape.getGlobalBounds().contains(mouse_position_f));

}
void Button::Draw(sf::RenderTarget*  window)
{
	window->draw(shape);
}

Button::Button(sf::Vector2f positions, sf::Vector2f  size_button, sf::Color button_color)
{
	color = button_color;
	shape.setFillColor(color);
	position = positions;
	shape.setPosition(position);
	size = size_button;
	shape.setSize(size);
	index++;
	key = index;
}


Button::~Button()
{
}
