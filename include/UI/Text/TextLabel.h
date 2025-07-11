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
	TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, sf::Color text_color, Orientation orientation = Orientation::Normal);
	TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, sf::Color text_color, Orientation orientation, sf::Vector2f center,int size =30);
	TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, sf::Color text_color, Orientation orientation,int size = 30);
	// ������ ����� ������������ ������ ������� �������
	// update ������� ����� �� ��������� ����� �����
	void setCenter(sf::Vector2f center, bool update = false);
	void setText(sf::String text);
	void setTextSize(int size);
	// ������������ ����� Widget
	void draw(sf::RenderTarget* window) override;
	void setPosition(sf::Vector2f new_position) override;
private:
	sf::FloatRect sizeRect;
	sf::Text text;
	Orientation orientation;
	sf::Vector2f center;
};