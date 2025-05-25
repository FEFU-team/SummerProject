#pragma once
#include <SFML/Graphics.hpp>
class Widget {
protected:
	// �������
	sf::Vector2f position;
	// ������
	int  scale = 0;
	// ����
	sf::Color color;
	// ��������
	sf::Texture texture;
public:
	// ������� ��������� �������
	virtual void draw(sf::RenderTarget* window) = 0;
	// ��������� ������� 
	sf::Vector2f getPosition();
	// �������� ������� 
	virtual void setPosition(sf::Vector2f new_position) = 0;
	// ���������  ....
	virtual  sf::FloatRect getBounds();
	// ��������� �����
	sf::Color getColor();
	// ������ ����
	virtual void setColor(sf::Color color);
	Widget();
	virtual ~Widget() = default;

};