#pragma once
#include "D:\SFML\SFML_TEST\src\Main.hpp"
#define const unsigned int HEIG2HT_WINDOW = 1920;//размер высоты окна
#define const unsigned  int WID2TH_WINDOW = 1080;//размер  ширины окна 
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