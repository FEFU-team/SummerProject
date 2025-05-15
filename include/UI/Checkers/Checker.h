#pragma once
#include"Elem.h"
class Checker:public Element
{
public:
	void move(sf::Vector2f vector);
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color);
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2f new_position) override;
	~Checker();
private:
	sf::CircleShape shape;

};