
#include <iostream>
#include "../include/UI/Button.h"
#include "../include/Engine.h"
#include <../include/UI/Map/Cell.h>
#include <UI/Map/Map.h>
#include <memory>
#include <GameBoardController.h>

void Engine::init()
{ 
    window = { std::make_unique<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
        "Checker")) };//умный указатель на окно
	window->setFramerateLimit(144);
   
}

void Engine::run()
{
    
    sf::Vector2f pos = {0,0};
    Map map(pos);
    //Controller controller;
    sf::Vector2i mouse_position_i;// позиция мыши 
    sf::Vector2f mouse_position_f;// позиция мыши 
    GameBoardController game;
    while (window->isOpen())
    {
        mouse_position_i = sf::Mouse::getPosition(*window);
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                game.update_input(&map.grid, mouse_position_f);
                //if (button.IsPressed(mouse_position_f)) button.Pressed();
            }
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            
        }
        window->clear();
       map.draw(window.get());
       //button.Draw(window);
       //button2.Draw(window);
       window->display();

  

    }
}

void Engine::end()
{
	
}

Engine::Engine()
{
}

Engine::~Engine()
{
}
