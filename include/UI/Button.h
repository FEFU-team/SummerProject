#pragma once
#include <SFML/Graphics.hpp>
#include <Elem.h>
//�����  ������� ������
class Button:Element {
protected:
	//������ ������ ������ � ������
	sf::Vector2f size;
	//�������������
	sf::RectangleShape shape;
	//����������
	unsigned  int key{};

public:
	//�������� ����������
	unsigned  int getKey();
	//������� �� ���������
	virtual void pressed();
	//������� �� ������
	virtual void OnClick();
	//����� ������ �� ������
	bool isPressed(sf::Vector2f mouse_position_f);
	//��������� ������
	void draw(sf::RenderTarget* window) override;
	//����������� � ����������� ������� . ������� {����� ������} � ���� 
	Button(sf::Vector2f positions, sf::Vector2f  size_button = { 100,100 } ,sf::Color button_color = sf::Color::White);
	~Button();
private:
	static inline unsigned index{};
	 
};