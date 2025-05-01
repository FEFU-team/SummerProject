#include "Engine.h"
#include "D:\SFML\SFML_TEST\src\Main.hpp"
void Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }),
		"CMake SFML Project"); // Объект окна
	window->setFramerateLimit(144);
}

void Engine::Run()
{
    while (window->isOpen())
    {
        while (const std::optional event = (window->pollEvent()))
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
