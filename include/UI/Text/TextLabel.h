#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
//Класс Текстового виджета
class TextLabel : public Widget {
public:

	TextLabel(sf::Font font,sf::String text);


	// Унаследовано через Widget
	void draw(sf::RenderTarget* window) override;

	void setPosition(sf::Vector2f new_position) override;
private:
	sf::String text;
	sf::Font font;
};