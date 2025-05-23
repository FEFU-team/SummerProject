#pragma once
#include <SFML/Graphics.hpp>
#include <UI/Buttons/Button.h>
#include<string>
class TextButton:Button {
public:
	void draw(sf::RenderTarget* window) override;
	TextButton(sf::Vector2f position, std::string text, sf::Color color = sf::Color::White);
private:
	sf::Font font;

};