#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>
#include <iostream>
void Checker::draw(sf::RenderTarget* window)
{
	window->draw(shape);
}
Checker::Checker(sf::Vector2f position, sf::Color color)
{
	this->color = color;
	this->position = position;
//	std::cout << "D" << std::endl;
	shape.setFillColor(color);
	shape.setRadius(25);
	//shape.setOutlineColor(sf::Color::Yellow);
	//shape.setOutlineThickness(5);
	shape.setPosition(position);
}
void Checker::setColor(sf::Color color)
{
	this->color = color;
	shape.setFillColor(color);
}
Checker::~Checker()
{
}