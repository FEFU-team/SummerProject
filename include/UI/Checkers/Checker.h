#pragma once
#include"Elem.h"
class Checker:public Element
{
public:
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color);
	~Checker();
	void setColor(sf::Color color);
	sf::Color getColor();
private:
	sf::CircleShape shape;

};