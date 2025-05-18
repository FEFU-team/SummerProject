#pragma once
#include <SFML/Graphics.hpp>
#include <Elem.h>
//Класс  обычной кнопки
class Button: public Element {
protected:
	//Прямоугольник
	sf::RectangleShape shape;
	//Размер кнопки длинна и ширина
	sf::Vector2f size;
	//Унификатор
	unsigned  int key{};

public:
	void setColor(sf::Color color) override;
	//Получить унификатор
	unsigned  int getKey();
	//Функция по умолчанию
	virtual void pressed();
	//Нажатие на кнопку
	//void OnClick();
	//Мышка нажала ли кнопка
	bool isPressed(sf::Vector2f mouse_position_f);
	//Отрисовка кнопки
	void draw(sf::RenderTarget* window) override;
	//Конструктор с параметрами позиции . размера {длина ширина} и цвет 
	Button(sf::Vector2f positions, sf::Vector2f  size_button = { 100,100 } ,sf::Color button_color = sf::Color::White);
	~Button();
private:
	static inline unsigned index{};
	
	 
};