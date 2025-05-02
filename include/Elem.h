#pragma once
#include <SFML/Graphics.hpp>
class Elem {
protected:
	//Позиция
	sf::Vector2f position;
	//Размер
	int  scale = 0;
	//Цвет
	sf::Color color;
	//Текстура
	sf::Texture texture;
public:
	//Функция отрисовки объекта
	virtual void draw(sf::RenderTarget* window);
	Elem();

};