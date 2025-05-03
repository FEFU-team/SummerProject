#pragma once
#include <SFML/Graphics.hpp>
class Element {
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
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f new_position);
	//Получение  ....
	virtual  sf::FloatRect getBounds();
	virtual sf::Color getColor();
	virtual void getColor(sf::Color);
	Element();

};