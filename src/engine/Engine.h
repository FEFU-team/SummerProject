#pragma once
#include "D:\SFML\SFML_TEST\src\Main.hpp"
const unsigned int HEIGHT_WINDOW = 1920;//������ ������ ����
const unsigned  int WIDTH_WINDOW = 1080;//������  ������ ���� 
class Engine
{
protected:
	sf::RenderWindow* window = nullptr;
public:
	void Init();
	void Run();
	void End();
	Engine();
	~Engine();

private:

};