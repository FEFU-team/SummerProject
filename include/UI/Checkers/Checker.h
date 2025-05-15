#pragma once
#include"Elem.h"
class Checker:public Element
{
public:
	void update(float time);
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color, float radius = 50);
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2f new_position) override;
	void start_move(sf::Vector2f target);
	~Checker();
private:
	sf::CircleShape shape;
	bool is_moving = false;
	sf::Vector2f target;

};