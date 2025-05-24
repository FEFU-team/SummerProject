#include "..\include\UI\\Menu\MainMenu.h"
#include <iostream>
#include <UI/Buttons/TextButton.h>

#include <memory>
#include <UI/Map/Cell.h>
MainMenu::MainMenu(sf::Vector2f position, unsigned int height, unsigned int width, GameController* game_controller_ptr) {
	this->position = position;
	this->game_controller_ptr = game_controller_ptr;
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f((height / 2) -100, (width / 2) -200), "Checkers", sf::Vector2f(200, 100),sf::Color::Black, sf::Color::White,60));
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f((height / 2) - 100, (width / 2) - 100), "Start", sf::Vector2f(200, 100)));
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f((height / 2) -100, (width / 2) + 50), "Exit", sf::Vector2f(200, 100)));

}
void MainMenu::draw(sf::RenderTarget* window)  {
	//widgets[0]->
	for (int i = 0; i < widgets.size(); i++) {
		widgets[i]->draw(window);
	}
}
void MainMenu::update_input(sf::Vector2f mouse_position) {
	if (widgets[1]->getBounds().contains(mouse_position)) {
		(*game_controller_ptr).setGameState(GameState::Play);
		std::cout << "Start" << std::endl;

	}
	else if(widgets[2]->getBounds().contains(mouse_position)) {
		(*game_controller_ptr).setGameState(GameState::End);
		std::cout << "Exit" << std::endl;
	}
	//if(widgets[)
}
/*
widgets.push_back(
std::make_unique<TextButton>(sf::Vector2f((height / 2) - 100, (width / 2) - 100), "Start", sf::Vector2f(100, 100)));
*/