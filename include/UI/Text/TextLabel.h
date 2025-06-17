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
//����� ���������� �������
class TextLabel : public Widget {
public:

	TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, Orientation orientation = Orientation::Normal);
	// ������ ����� ������������ ������ ������� �������
	void setCenter(sf::Vector2f center);
	// ������ ����� ������������ ��������� 
	void setCenter();
	void setText(sf::String text);
	// ������������ ����� Widget
	void draw(sf::RenderTarget* window) override;
	void setPosition(sf::Vector2f new_position) override;
private:
	sf::FloatRect sizeRect;
	sf::Text text;
};