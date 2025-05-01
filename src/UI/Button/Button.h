#pragma once
#include "D:\SFML\SFML_TEST\src\Main.hpp"
#include<string>
class Button {
protected:
	sf::Vector2f position;
	float size = 10;
public:
	void Pressed();
	Button(sf::Vector2f positions);
	~Button();
};