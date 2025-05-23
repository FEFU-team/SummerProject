#pragma once
#include "Main.hpp"
#include <memory>
#include "GameController.h"
const unsigned int HEIGHT_WINDOW = 1920;//размер высоты окна
const unsigned  int WIDTH_WINDOW = 1080;//размер  ширины окна 
class Engine
{
protected:
	std::unique_ptr<sf::RenderWindow> window;
	GameController game_controller;
public:
	//Инициализация
	void init();
	//Работа в окне
	void run();
	//Завершение
	void end();
	Engine();
	~Engine();

private:

};