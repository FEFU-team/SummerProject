#pragma once
#include <SFML/Graphics.hpp>
class Element{
protected:
	// Позиция
	sf::Vector2f position;
	// Размер
	int  scale = 0;
	// Цвет
	sf::Color color;
	// Текстура
	sf::Texture texture;
public:
	// Функция отрисовки объекта
	virtual void draw(sf::RenderTarget* window) = 0;
	// Получение позиции 
	sf::Vector2f getPosition();
	// Задается позиция 
	virtual void setPosition(sf::Vector2f new_position) = 0;
	// Получение  ....
	virtual  sf::FloatRect getBounds();
	// Получение цвета
	sf::Color getColor();
	// Задаем цвет
	virtual void setColor(sf::Color color);
	Element();
	virtual ~Element() = default;

};