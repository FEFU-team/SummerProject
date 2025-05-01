#pragma once
#include "D:\SFML\SFML_TEST\src\Main.hpp"
const unsigned int HEIGHT_WINDOW = 1920;//размер высоты окна
const unsigned  int WIDTH_WINDOW = 1080;//размер  ширины окна 
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