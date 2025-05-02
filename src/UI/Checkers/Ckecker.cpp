#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>
void Checker::draw(sf::RenderTarget* window)
{
	window->draw(shape);
}
Checker::Checker(sf::Vector2f position, sf::Color color)
{
	this->color = color;
	this->position = position;
	shape.setFillColor(color);
	shape.setRadius(25);
	shape.setPosition(position);
}
Checker::~Checker()
{
}