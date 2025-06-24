#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<vector>
#include <Core/AssetManager.h>
using namespace std;
class GameBoard: public Widget {
public:
	void draw(sf::RenderTarget* window) override;
	//������� ��������� ����
	void draw(sf::RenderTarget* window, float delta_time);
	GameBoard(sf::Vector2f positions, AssetManager* assets);
	// ����� �������� ����
	std::vector<std::vector<std::unique_ptr<Cell>>> grid;
	// ������������ ����� Widget
	void setPosition(sf::Vector2f new_position) override;
	void reset();
private:
	// ����� ����
	const  int HEIGHT = 8;
	// ������ ����
	const  int WIDTH = 8;
	// ��������� �� �������� �������
	AssetManager* assets;


};