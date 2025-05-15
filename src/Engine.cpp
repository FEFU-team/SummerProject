
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
	window->setFramerateLimit(144);
   
}

void Engine::run()
{
    
    sf::Vector2f pos = {0,0};
    GameBoard map(pos);
    sf::Clock clock;
    sf::Vector2i mouse_position_i;// позиция мыши 
    sf::Vector2f mouse_position_f;// позиция мыши 
   GameBoardController game(&map.grid);
    //Checker checker(sf::Vector2f(0,0), sf::Color::Green);
    //Checker checker2(sf::Vector2f(500, 100), sf::Color::White);
    while (window->isOpen())
    {
        //checker.start_move({ 10,10 });
        //checker2.start_move({ 0,0 });
        float delta_time = clock.restart().asSeconds();
        mouse_position_i = sf::Mouse::getPosition(*window);
        mouse_position_f = window->mapPixelToCoords(mouse_position_i);
        while (std::optional event = window->pollEvent())
        {
            game.update_time(delta_time);
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
        //checker.update_move(delta_time/100);
       // checker2.update_move(delta_time);
        window->clear();
        //checker.draw(window.get());
        //checker2.draw(window.get());;
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
