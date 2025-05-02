#pragma once
#include "Main.hpp"
const unsigned int HEIGHT_WINDOW = 1920;//размер высоты окна
const unsigned  int WIDTH_WINDOW = 1080;//размер  ширины окна 
class Engine
{
protected:
	sf::RenderWindow* window = nullptr;
public:
	//Инициализация
	void Init();
	//Работа в окне
	void Run();
	//Завершение
	void End();
	Engine();
	~Engine();

private:

};