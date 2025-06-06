#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>
#include <iostream>

void Checker::draw(sf::RenderTarget* window)
{
	window->draw(shape);
}
Checker::Checker(sf::Vector2f position, sf::Color color, float radius, sf::Texture texture)
{
	//texture.loadFromFile(R"(../../../../assets/texture/checkers.jpg)");
	//texture.setSmooth(true);
	this->texture = texture;
	shape.setTexture(&texture);
	position.x = position.x + 1;
	position.y = position.y + 1;
	this->color = color;
	this->position = position;
	shape.setFillColor(color);
	//shape.setSize({50,50});
	shape.setRadius(radius);
	shape.setPosition(position);
	//shape.setPointCount(100000);
	if (color == sf::Color::Yellow) { // Тут нужно еще цвет менять для шашки
		color_checker = ColorChecker::Black;
	}
	else {
		color_checker = ColorChecker::White;
	}
	
	
}
void Checker::setColor(sf::Color color)
{
	this->color = color;
	shape.setFillColor(color);
}
ColorChecker Checker::getColorChecker() {
	return color_checker;
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
 
bool Checker::is_move(){
	return is_moving;
}
Checker::~Checker()
{
}