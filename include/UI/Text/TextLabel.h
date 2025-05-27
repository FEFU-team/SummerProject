#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
//����� ���������� �������
class TextLabel : public Widget {
public:

	TextLabel(sf::Vector2f position, sf::Font font, sf::String text);

	void setText(sf::String text);
	// ������������ ����� Widget
	void draw(sf::RenderTarget* window) override;

	void setPosition(sf::Vector2f new_position) override;
private:
	sf::String text;
	sf::Font font;
};