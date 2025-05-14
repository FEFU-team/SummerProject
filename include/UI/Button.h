#pragma once
#include <SFML/Graphics.hpp>
#include <Elem.h>
//�����  ������� ������
class Button: public Element {
protected:
	//�������������
	sf::RectangleShape shape;
	//������ ������ ������ � ������
	sf::Vector2f size;
	//����������
	unsigned  int key{};

public:
	void setColor(sf::Color color) override;
	//�������� ����������
	unsigned  int getKey();
	//������� �� ���������
	virtual void pressed();
	//������� �� ������
	//void OnClick();
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