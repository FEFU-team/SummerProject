#include "Engine.h"
#include "D:\SFML\SFML_TEST\src\Main.hpp"
#include <iostream>
void Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
		"CMake SFML Project"); // Объект окна
	window->setFramerateLimit(144);
}

void Engine::Run()
{
    while (window->isOpen())
    {
        while (std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
        }
        window->clear();
        window->display();

  

    }
}

void Engine::End()
{
	if (window != nullptr) {
		delete window;
	}
}

Engine::Engine()
{
}

Engine::~Engine()
{
}
