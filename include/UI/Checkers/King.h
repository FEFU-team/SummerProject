#pragma once
#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>
#include <iostream>
class King :public Checker {
public:
	King(sf::Vector2f position, sf::Color color, sf::Texture* texture);
};