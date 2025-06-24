
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
#include <UI/Info/Info.h>
#include <UI/End/End.h>


void Engine::init()
{ 
    assets.uploadFont("arial", "../../../../assets/fonts/arialmt.ttf");
    assets.uploadTexture("checker1", "../../../../assets/texture/checkers2.png");
    assets.uploadTexture("checker_active", "../../../../assets/texture/checkers3.jpeg");
    assets.uploadTexture("queen", "../../../../assets/texture/queen.png");
    window = { std::make_unique<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({ HEIGHT_WINDOW, WIDTH_WINDOW }),
        L"Шашки FEFU")) };
	window->setFramerateLimit(144);
   
}

void Engine::run()
{
   
    sf::Vector2f position_board = {2,1}; 
    GameBoard game_board(position_board,&assets);
    sf::Vector2i mouse_position_i;
    sf::Vector2f mouse_position_f;
    GameBoardController game_board_controller(&game_board.grid,&assets);
    sf::Clock clock;
    MainMenu main_menu({ 0,0 }, HEIGHT_WINDOW, WIDTH_WINDOW, assets.getFont("arial"), &game_controller);
    Info info({ 1100,0 }, assets.getFont("arial"), &game_controller);
    End end({ HEIGHT_WINDOW/2,WIDTH_WINDOW/2 }, assets.getFont("arial"),L"Победили", &game_controller);


    game_board.grid[0][5]->getChecker()->becoming_queen(assets.getTexture("queen"));

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
                else if(current_state == GameState::Play) {
                    info.update_input(mouse_position_f);
                    game_board_controller.update_input(mouse_position_f);
                }
                else if (current_state == GameState::End) {
                    end.update_input(mouse_position_f);
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

        }
        else if (current_state == GameState::End) {
            end.draw(window.get());
        }
        else if(current_state == GameState::Play){
            
            ColorChecker ch = game_board_controller.getCurrentPlayer();
            if (ch == ColorChecker::Black) {
                info.update_info(L"Желтые");
            }
            else {
               info.update_info(L"Зеленые");
            }
            
            game_board.draw(window.get(), time);
            info.draw(window.get());
        }
        else if (current_state == GameState::Restart) {
            game_board.reset();
            game_board_controller.reset();
            cout << "Restart" << endl;
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
