#pragma once
#include <SFML/Graphics.hpp>
#include <UI/Buttons/Button.h>
#include<string>
class TextButton: public Button {
public:
	// Допилить много чего
	// Получаем текст
	std::string getText();
	// задаем текст
	void setText(std::string text);
	// Задаем цвет текста
	void setTextColor(sf::Color text_color);
	// Отрисовка кнопки
	void draw(sf::RenderTarget* window) override;
	TextButton(sf::Vector2f position, std::string text, sf::Color button_color = sf::Color::White);
private:
	sf::Font font;
	std::string text;


};