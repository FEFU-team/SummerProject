#pragma once
#include "Main.hpp"
const unsigned int HEIGHT_WINDOW = 1920;//������ ������ ����
const unsigned  int WIDTH_WINDOW = 1080;//������  ������ ���� 
class Engine
{
protected:
	sf::RenderWindow* window = nullptr;
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