#pragma once
#include <SFML/Graphics.hpp>
#include <UI/Buttons/Button.h>
#include<string>
class TextButton: public Button {
public:

	void setTextSize(unsigned int size);
	// Допилить много чего
	// Получаем текст
	std::string getText();
	// задаем текст
	void setText(std::string text);
	// Задаем цвет текста
	void setTextColor(sf::Color text_color);
	// Отрисовка кнопки
	void draw(sf::RenderTarget* window) override;
	TextButton(sf::Vector2f position, sf::String text, sf::Vector2f size = { 100,100 }, sf::Color button_color = sf::Color::White, sf::Color text_color = sf::Color::Black, unsigned int text_size = 30);
private:
	sf::Font font;
	sf::String text;
	sf::Color text_color;
	unsigned int text_size;

};