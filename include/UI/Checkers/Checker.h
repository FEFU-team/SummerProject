#pragma once
#include"Widget.h"
// Состояние шашки
enum ColorChecker {
	White,
	Black,
};
class Checker:public Widget
{
public:
	// Получение цвета шашки
	ColorChecker getColorChecker();
	// Обновление позиции шашки
	void update(float time);
	// Отрисовка шашки
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color, float radius = 49,sf::Texture texture);
	// Задаем цвет
	void setColor(sf::Color color) override;
	// Задаем позицию 
	void setPosition(sf::Vector2f new_position) override;
	// Запускам анимацию перемещения
	void start_move(sf::Vector2f target);
	bool is_move();
	~Checker();
protected:
	enum ColorChecker color_checker;
	sf::CircleShape shape;
private:
	bool is_moving = false;
	sf::Vector2f target;
	

};
