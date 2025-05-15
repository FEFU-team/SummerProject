
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
        "Checker")) };//умный указатель на окно
	window->setFramerateLimit(60);
   
}

void Engine::run()
{
    
    sf::Vector2f pos = {0,0};
    GameBoard map(pos);
    //Controller controller;
    sf::Vector2i mouse_position_i;// позиция мыши 
    sf::Vector2f mouse_position_f;// позиция мыши 
    GameBoardController game(&map.grid);
    sf::Clock clock;
    //Checker checker(pos, sf::Color::Green,10);
    //Checker checker1({ 100,100 }, sf::Color::White,10);
    //checker.start_move({100,100});
    while (window->isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        time = time / 100;
        mouse_position_i = sf::Mouse::getPosition(*window);
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                game.update_input(mouse_position_f);
                
                //if (button.IsPressed(mouse_position_f)) button.Pressed();
                //checker.move(sf::Vector2f(10, 10));
            }
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            
        }
        game.update_animation(time);
        //checker.update(time);
        window->clear();
        //checker.draw(window.get());
        //checker1.draw(window.get());
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
