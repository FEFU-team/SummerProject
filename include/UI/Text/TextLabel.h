#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
enum class Orientation
{
	Normal,
	Center,
	Right,
	Left

};
//Класс Текстового виджета
class TextLabel : public Widget {
public:

	TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, Orientation orientation = Orientation::Normal);
	// Задаем центр относительно центра другого обьекта
	void setCenter(sf::Vector2f center);
	// Задаем центр относительно координат 
	void setCenter();
	void setText(sf::String text);
	// Унаследовано через Widget
	void draw(sf::RenderTarget* window) override;
	void setPosition(sf::Vector2f new_position) override;
private:
	sf::FloatRect sizeRect;
	sf::Text text;
};