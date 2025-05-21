
#include <iostream>
#include "../include/UI//Buttons/Button.h"
#include "../include/Core/Engine.h"
#include <../include/UI/Map/Cell.h>
#include <UI/Map/GameBoard.h>
#include <memory>
#include <Core/GameBoardController.h>
#include <Core/GameController.h>
#include <filesystem>  // C++17


void Engine::init()
{ 
    
    window = { std::make_unique<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
        L"Checkers")) };
	window->setFramerateLimit(60);
   
}

void Engine::run()
{
    GameController game_controller;
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
        if (current_state == GameState::Init) {
            //cout << "Init" << endl;
             sf::Font font("../../../../assets/fonts/arialmt.ttf");
             sf::Text text(font);
             // set the string to display
             text.setString("Hello world");
             text.setPosition({ 100,100 });
             // set the character size
             text.setCharacterSize(100); // in pixels, not points!

             // set the color
             text.setFillColor(sf::Color::Red);
             window->draw(text);
            //game_controller.setGameState(GameState::Start);
        }
        else {
            game_board.draw(window.get(), time);
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
