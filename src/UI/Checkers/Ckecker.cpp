#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>
#include <iostream>

void Checker::draw(sf::RenderTarget* window)
{
	window->draw(shape);
}
Checker::Checker(sf::Vector2f position, sf::Color color, float radius)
{
	this->color = color;
	this->position = position;
//	std::cout << "D" << std::endl;
	shape.setFillColor(color);
	shape.setRadius(radius);
	//shape.setOutlineColor(sf::Color::Yellow);
	//shape.setOutlineThickness(5);
	shape.setPosition(position);
}
void Checker::setColor(sf::Color color)
{
	this->color = color;
	shape.setFillColor(color);
}

void Checker::setPosition(sf::Vector2f new_position)
{
	this->position = new_position;
	shape.setPosition(new_position);
}
void Checker::start_move(sf::Vector2f target)
{
	this->target = target;
	is_moving = true;
}
void Checker::update(float time)
{
	
    if (!is_moving) {
        return;
    }

    sf::Vector2f direction = target- position;
    float distance = std::hypot(direction.x, direction.y);
	//std::cout << distance << std::endl;
	if (distance < 1.f) {
		position = target;
		shape.setPosition(position);
		is_moving = false;
		return;
	}
	sf::Vector2f offset = (direction / distance) *( 15 * time);
	shape.move(offset);

    position = shape.getPosition();
}
Checker::~Checker()
{
}