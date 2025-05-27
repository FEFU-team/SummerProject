#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
//Класс  обычной прямоугольной  кнопки
class Button: public Widget {
protected:
	//Прямоугольник
	sf::RectangleShape shape;
	//Размер кнопки длинна и ширина
	sf::Vector2f size;
	//Унификатор
	unsigned  int key{};

public:
	sf::FloatRect getBounds() override;
	void setColor(sf::Color color) override;
	//Получить унификатор
	unsigned  int getKey();
	//Функция по умолчанию
	virtual void pressed() const;
	//Нажатие на кнопку
	//void OnClick();
	//Мышка нажала ли кнопка
	bool isPressed(sf::Vector2f mouse_position_f);
	//Отрисовка кнопки
	void draw(sf::RenderTarget* window) override;
	//Конструктор с параметрами позиции . размера {длина ширина} и цвет 
	Button(sf::Vector2f positions, sf::Vector2f  size_button = { 100,100 } ,sf::Color button_color = sf::Color::White);
	~Button();
	// Унаследовано через Element
	void setPosition(sf::Vector2f new_position) override;
private:
	static inline unsigned index{};

};