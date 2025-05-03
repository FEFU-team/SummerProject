#pragma once
#include <SFML/Graphics.hpp>
class Element {
protected:
	//�������
	sf::Vector2f position;
	//������
	int  scale = 0;
	//����
	sf::Color color;
	//��������
	sf::Texture texture;
public:
	//������� ��������� �������
	virtual void draw(sf::RenderTarget* window);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f new_position);
	//���������  ....
	virtual  sf::FloatRect getBounds();
	virtual sf::Color getColor();
	virtual void getColor(sf::Color);
	Element();

};