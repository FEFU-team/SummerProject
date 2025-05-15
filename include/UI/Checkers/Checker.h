#pragma once
#include"Elem.h"
class Checker:public Element
{
public:
	void update_move(float delta_time);
	void start_move(sf::Vector2f target);
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color);
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2f new_position) override;
	~Checker();
private:
	sf::CircleShape shape;

};