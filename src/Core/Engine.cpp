
#include <iostream>
#include "../include/UI//Buttons/Button.h"
#include "../include/Core/Engine.h"
#include <../include/UI/Map/Cell.h>
#include <UI/Map/GameBoard.h>
#include <memory>
#include <Core/GameBoardController.h>
#include <New elem.h>


void Engine::init()
{ 
    window = { std::make_unique<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
        "Checker")) };//умный указатель на окно
	window->setFramerateLimit(60);
   
}

void Engine::run()
{
    
    sf::Vector2f position_board = {0,0}; //  оординаты игрового пол€
    GameBoard game_board(position_board);
    sf::Vector2i mouse_position_i;// позици€ мыши 
    sf::Vector2f mouse_position_f;// позици€ мыши 
    GameBoardController game_board_controller(&game_board.grid);
    sf::Clock clock;
    while (window->isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds(); // задаем таймер
        clock.restart();
        time = time / 100;
        mouse_position_i = sf::Mouse::getPosition(*window);
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                game_board_controller.update_input(mouse_position_f);
            }
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            
        }
        window->clear();
       game_board.draw(window.get(),time);
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
