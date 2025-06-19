#pragma once
#include"Widget.h"
// ��������� �����
enum ColorChecker {
	White,
	Black,
};
class Checker:public Widget
{
public:
	// ��������� ����� �����
	ColorChecker getColorChecker();
	// ���������� ������� �����
	void update(float time);
	// ��������� �����
	void draw(sf::RenderTarget* window) override;
	Checker(sf::Vector2f position,sf::Color color, sf::Texture* texture, float radius = 49);
	// ������ ����
	void setColor(sf::Color color) override;
	// ������ ������� 
	void setPosition(sf::Vector2f new_position) override;
	// �������� �������� �����������
	void start_move(sf::Vector2f target);
	// �������� �� ����� 
	bool is_move();
	// ���������� �������� ��� ��������� 
	void update_texture(sf::Texture* texture,bool active);
	// �������� ��
	bool is_active();
	// ����� ��
	bool is_queen();
	// ����������� ������
	void becoming_queen(sf::Texture* texture);
	~Checker();
protected:
	enum ColorChecker color_checker;
	sf::CircleShape shape;
private:
	bool is_moving = false;
	sf::Vector2f target;
	bool active = false;;
	bool queen = false;
	

};
