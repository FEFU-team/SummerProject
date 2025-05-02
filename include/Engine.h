#pragma once
#include "Main.hpp"
#include <memory>
const unsigned int HEIGHT_WINDOW = 1920;//������ ������ ����
const unsigned  int WIDTH_WINDOW = 1080;//������  ������ ���� 
class Engine
{
protected:
	std::unique_ptr<sf::RenderWindow> window;
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