#pragma once
#include <SFML/Graphics.hpp>
#include <Elem.h>
//Класс  обычной кнопки
class Button:Elem {
protected:
	//Размер кнопки длинна и ширина
	sf::Vector2f size;
	//Прямоугольник
	sf::RectangleShape shape;
	//Унификатор
	unsigned  int key{};

public:
	//Получить унификатор
	unsigned  int getKey();
	//Функция по умолчанию
	virtual void Pressed();
	//Мышка нажала ли кнопка
	bool IsPressed(sf::Vector2f mouse_position_f);
	//Отрисовка кнопки
	void Draw(sf::RenderTarget* window) override;
	//Конструктор с параметрами позиции . размера {длина ширина} и цвет 
	Button(sf::Vector2f positions, sf::Vector2f  size_button = { 100,100 } ,sf::Color button_color = sf::Color::White);
	~Button();
private:
	static inline unsigned index{};
	 
};