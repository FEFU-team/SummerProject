#pragma once
#include"Elem.h"
class Checker:public Element
{
public:
	void start_move(sf::Vector2f vector);
	void end_move();
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color);
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2f new_position) override;
	void update_move(float time);
	~Checker();
private:
	sf::CircleShape shape;
	sf::Vector2f target;
	bool is_moving = false;


};