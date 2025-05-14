#pragma once
#include"Elem.h"
class Checker:public Element
{
public:
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color);
	void setColor(sf::Color color) override;
	~Checker();
private:
	sf::CircleShape shape;

};