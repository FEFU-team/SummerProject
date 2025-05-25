#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
//�����  ������� �������������  ������
class Button: public Widget {
protected:
	//�������������
	sf::RectangleShape shape;
	//������ ������ ������ � ������
	sf::Vector2f size;
	//����������
	unsigned  int key{};

public:
	sf::FloatRect getBounds() override;
	void setColor(sf::Color color) override;
	//�������� ����������
	unsigned  int getKey();
	//������� �� ���������
	virtual void pressed() const;
	//������� �� ������
	//void OnClick();
	//����� ������ �� ������
	bool isPressed(sf::Vector2f mouse_position_f);
	//��������� ������
	void draw(sf::RenderTarget* window) override;
	//����������� � ����������� ������� . ������� {����� ������} � ���� 
	Button(sf::Vector2f positions, sf::Vector2f  size_button = { 100,100 } ,sf::Color button_color = sf::Color::White);
	~Button();
	// ������������ ����� Element
	void setPosition(sf::Vector2f new_position) override;
private:
	static inline unsigned index{};

};