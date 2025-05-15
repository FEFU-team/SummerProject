
#include <iostream>
#include "../include/UI/Button.h"
#include "../include/Engine.h"
#include <../include/UI/Map/Cell.h>
#include <UI/Map/GameBoard.h>
#include <memory>
#include <GameBoardController.h>

void Engine::init()
{ 
    window = { std::make_unique<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
        "Checker")) };//����� ��������� �� ����
	window->setFramerateLimit(144);
   
}

void Engine::run()
{
    
    sf::Vector2f pos = {0,0};
   // GameBoard map(pos);
    //Controller controller;
    sf::Clock clock;
    sf::Vector2i mouse_position_i;// ������� ���� 
    sf::Vector2f mouse_position_f;// ������� ���� 
   // GameBoardController game(&map.grid);
    float delta_time;
   Checker checker(sf::Vector2f(900,0), sf::Color::Yellow);
    while (window->isOpen())
    {
        mouse_position_i = sf::Mouse::getPosition(*window);
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
               
                //game.update_input(mouse_position_f);
                //if (button.IsPressed(mouse_position_f)) button.Pressed();
                //checker.move(sf::Vector2f(10, 10));
            }
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            
        }
        
        window->clear();
        checker.draw(window.get());
      // map.draw(window.get());
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
