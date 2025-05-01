#include "Button.h"

void Button::Pressed()
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
}


Button::~Button()
{
}
