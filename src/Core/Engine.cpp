
#include <iostream>
#include "../include/UI//Buttons/Button.h"
#include "../include/Core/Engine.h"
#include <../include/UI/Map/Cell.h>
#include <UI/Map/GameBoard.h>
#include <memory>

#include <filesystem>  // C++17
#include <Core/GameBoardController.h>
#include <UI/Buttons/TextButton.h>


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
    while (window->isOpen())
    {
        GameState  current_state = game_controller.getGameState();
        float time = clock.getElapsedTime().asMilliseconds(); 
        clock.restart();
        time = time / 100;
        mouse_position_i = sf::Mouse::getPosition(*window);
        Button button({ 100,100 }, { 600,100 });
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                game_board_controller.update_input(mouse_position_f);
                if (button.isPressed(mouse_position_f)) {
                    game_controller.setGameState(GameState::Start);
                }
            }
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            
        }
        window->clear();
        if (current_state == GameState::Init) {
            //TextButton button({ 100,100 },"Hello");
            //button.draw(window.get());
             


            //game_controller.setGameState(GameState::Start);
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
