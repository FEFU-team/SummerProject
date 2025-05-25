#pragma once
#include "Main.hpp"
#include <memory>
#include "GameController.h"
#include "../include/Core/AssetManager.h"
const unsigned int HEIGHT_WINDOW = 1920;//размер высоты окна
const unsigned  int WIDTH_WINDOW = 1080;//размер  ширины окна 
// Отвечает за работу основной программы
class Engine
{
private:
	std::unique_ptr<sf::RenderWindow> window;
	GameController game_controller;
	AssetManager asset_manager;

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