
#include <iostream>
#include <SFML/Graphics.hpp>
#include <UI/Buttons/Button.h>
sf::FloatRect Button::getBounds()
{
	return shape.getGlobalBounds();
}
void Button::setColor(sf::Color color)
{
	this->color = color;
	shape.setFillColor(color);
}
unsigned int Button::getKey()
{
	return key;
}

void Button::pressed() const
{
	std::cout << "Hello" << std::endl;
}

bool Button::isPressed(sf::Vector2f mouse_position_f)
{
	return shape.getGlobalBounds().contains(mouse_position_f);

}

void Button::draw(sf::RenderTarget*  window)
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

void Button::setPosition(sf::Vector2f new_position)
{
	this->position = new_position;
	shape.setPosition(position);
}
