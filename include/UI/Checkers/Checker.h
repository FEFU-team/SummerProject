#pragma once
#include"Elem.h"
class Checker:public Elem
{
public:
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color);
	~Checker();

private:
	sf::CircleShape shape;

};