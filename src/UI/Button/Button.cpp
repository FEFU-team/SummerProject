#include "Button.h"
#include <iostream>

unsigned int Button::getKey()
{
	return key;
}

void Button::Pressed()
{
	std::cout << "Hello" << std::endl;
}
bool Button::IsPressed(sf::RenderWindow* window)
{

}
void Button::Draw(sf::RenderTarget*  window)
{
	window->draw(shape);
}

Button::Button(sf::Vector2f positions, sf::Vector2f  size_button)
{
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
