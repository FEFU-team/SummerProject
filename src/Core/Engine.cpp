
#include <iostream>
#include "../include/UI//Buttons/Button.h"
#include "../include/Core/Engine.h"
#include <../include/UI/Map/Cell.h>
#include <UI/Map/GameBoard.h>
#include <memory>

#include <filesystem>  // C++17
#include <Core/GameBoardController.h>
#include <UI/Buttons/TextButton.h>
#include <UI/Menu/MainMenu.h>


void Engine::init()
{ 
    
    window = { std::make_unique<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
        L"Checkers")) };
	window->setFramerateLimit(144);
   
}

void Engine::run()
{
   
    sf::Vector2f position_board = {0,0}; 
    GameBoard game_board(position_board);
    sf::Vector2i mouse_position_i;
    sf::Vector2f mouse_position_f;
    GameBoardController game_board_controller(&game_board.grid);
    sf::Clock clock;
    MainMenu main_menu({ 0,0 }, HEIGHT_WINDOW,WIDTH_WINDOW, &game_controller);
    while (window->isOpen())
    {
        GameState  current_state = game_controller.getGameState();
        float time = clock.getElapsedTime().asMilliseconds(); 
        clock.restart();
        time = time / 100;
        mouse_position_i = sf::Mouse::getPosition(*window);
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (current_state == GameState::Init) {
                    main_menu.update_input(mouse_position_f);
                }
                else {
                    game_board_controller.update_input(mouse_position_f);
                }
               
                
            }
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            
        }
        window->clear(sf::Color::Black);
        if (current_state == GameState::Init) {
          
            main_menu.draw(window.get());

            //game_controller.setGameState(GameState::Start);
        }
        else if (current_state == GameState::End) {
            window->close();
        }
        else {
            game_board.draw(window.get(), time);
            game_controller.setGameState(GameState::Play);
        }
     
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
