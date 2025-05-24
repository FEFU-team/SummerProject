#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
using namespace std;
class GameBoard: public Element {
public:
	void draw(sf::RenderTarget* window) override;
	//������� ��������� ����
	void draw(sf::RenderTarget* window, float delta_time);
	GameBoard(sf::Vector2f positions = {0,0});
	// ����� �������� ����
	std::vector<std::vector<std::unique_ptr<Cell>>> grid;
	// ������������ ����� Element
	void setPosition(sf::Vector2f new_position) override;
private:
	// ����� ����
	const  int HEIGHT = 8;
	// ������ ����
	const  int WIDTH = 8;

};