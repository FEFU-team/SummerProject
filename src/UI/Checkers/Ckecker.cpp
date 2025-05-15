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
	shape.setRadius(50);
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
void Checker::update_move(float time)
{
	if (!is_moving) {
		return;
	}

    // Расчёт направления движения
    sf::Vector2f direction = target - position;
    float distance = std::hypot(direction.x, direction.y);

    // Если достигли цели
    if (distance < 10.f) {
        position = target;
        shape.setPosition(position);
		end_move();
        return;
    }

    // Нормализация направления и умножение на скорость
    sf::Vector2f offset = (direction / distance)  * (time*100);

	shape.move(offset);
}
void Checker::start_move(sf::Vector2f vector)
{
    target = vector;
	is_moving = true;
}
void Checker::end_move()
{
	is_moving = false;
}
Checker::~Checker()
{
}