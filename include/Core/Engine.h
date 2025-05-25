#pragma once
#include "Main.hpp"
#include <memory>
#include "GameController.h"
#include "../include/Core/AssetManager.h"
const unsigned int HEIGHT_WINDOW = 1920;//������ ������ ����
const unsigned  int WIDTH_WINDOW = 1080;//������  ������ ���� 
// �������� �� ������ �������� ���������
class Engine
{
private:
	std::unique_ptr<sf::RenderWindow> window;
	GameController game_controller;
	AssetManager asset_manager;

public:
	//�������������
	void init();
	//������ � ����
	void run();
	//����������
	void end();
	Engine();
	~Engine();

private:

};