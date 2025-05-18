#pragma once
#include"Elem.h"
class Checker:public Element
{
public:
	// Обновление позиции шашки
	void update(float time);
	// Отрисовка шашки
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color, float radius = 49);
	// Задаем цвет
	void setColor(sf::Color color) override;
	// Задаем позицию 
	void setPosition(sf::Vector2f new_position) override;
	// Запускам анимацию перемещения
	void start_move(sf::Vector2f target);
	~Checker();
private:
	sf::CircleShape shape;
	bool is_moving = false;
	sf::Vector2f target;
	enum ColorChecker color_checker;

};
// Состояние шашки
enum ColorChecker {
	White,
	Black,
};