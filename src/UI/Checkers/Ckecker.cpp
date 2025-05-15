#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>
#include <iostream>

void Checker::update_move(float delta_time)
{
	if (!is_moving) return; // Если не движемся - выход

	// Расчет направления движения
	sf::Vector2f direction = target - position;
	float distance = std::hypot(direction.x, direction.y);

	// Проверка достижения цели
	if (distance < 1.f) {
		position = target;
		shape.setPosition(position);
		is_moving = false;
		return;
	}

	// Расчет смещения
	sf::Vector2f offset = (direction / distance) * (100 * delta_time);

	// Обновление позиции
	position += offset;
	shape.setPosition(position);
}

void Checker::start_move(sf::Vector2f target)
{
	is_moving = true;
	this->target = target;
}

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
Checker::~Checker()
{
}