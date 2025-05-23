#pragma once
#include "Main.hpp"
#include <memory>
#include "GameController.h"
const unsigned int HEIGHT_WINDOW = 1920;//������ ������ ����
const unsigned  int WIDTH_WINDOW = 1080;//������  ������ ���� 
class Engine
{
protected:
	std::unique_ptr<sf::RenderWindow> window;
	GameController game_controller;
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