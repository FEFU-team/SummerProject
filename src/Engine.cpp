
#include <iostream>
#include "../include/UI/Button.h"
#include "../include/Engine.h"
#include <UI/Map/Cell.h>
void Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
		"CMake SFML Project"); // Объект окна
	window->setFramerateLimit(144);
}

void Engine::Run()
{
    sf::Vector2f pos = { 10,100};
    Button button(pos
    );
    Button button2({50,300}
    );
    Cell cell();
    sf::Vector2i mouse_position_i;// позиция мыши 
    sf::Vector2f mouse_position_f;// позиция мыши 
    while (window->isOpen())
    {
        mouse_position_i = sf::Mouse::getPosition(*window);
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (button.IsPressed(mouse_position_f)) button.Pressed();
            
            }
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
        }
        window->clear();
        button.Draw(window);
        button2.Draw(window);
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
