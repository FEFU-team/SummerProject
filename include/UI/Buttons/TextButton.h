#pragma once
#include <SFML/Graphics.hpp>
#include <UI/Buttons/Button.h>
#include<string>
#include <UI/Text/TextLabel.h>
class TextButton: public Button {
public:

	void setTextSize(unsigned int size);
	// �������� ����� ����
	// �������� �����
	std::string getText();
	// ������ �����
	void setText(std::string text);
	// ������ ���� ������
	void setTextColor(sf::Color text_color);
	// ��������� ������
	void draw(sf::RenderTarget* window) override;

	TextButton(sf::Vector2f positon, sf::String text, sf::Font* font);

	TextButton(sf::Vector2f position, sf::String text,  sf::Font* font, unsigned int text_size,sf::Vector2f size_button,sf::Color button_color, sf::Color text_color);

private:
	sf::String text;
	sf::Color text_color;
	unsigned int text_size = 30;
	TextLabel text_label;

};