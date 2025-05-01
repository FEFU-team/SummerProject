#pragma once
#include "D:\SFML\SFML_TEST\src\Main.hpp"
#include<string>
class Button {
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape shape;
public:
	void Pressed();
	void Draw(sf::RenderTarget* window);
	Button(sf::Vector2f positions, sf::Vector2f  size_button = { 100,100 });
	~Button();
};