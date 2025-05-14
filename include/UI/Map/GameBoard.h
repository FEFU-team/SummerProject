#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
using namespace std;
class GameBoard: public Element {
private:
	// ����� ����
	 const  int HEIGHT = 8;
	// ������ ����
	 const  int WIDTH = 8;
	
public:
	//������� ��������� ����
	void draw(sf::RenderTarget* window) override;
	GameBoard(sf::Vector2f positions = {0,0});
	// ����� �������� ����
	std::vector<std::vector<std::unique_ptr<Cell>>> grid;
};