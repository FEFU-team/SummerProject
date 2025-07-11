#include "..\include\UI\\Menu\MainMenu.h"
#include <iostream>
#include <UI/Buttons/TextButton.h>

#include <memory>
#include <UI/Map/Cell.h>
#include <UI/Text/TextLabel.h>
#include <UI/SizeBox.h>
MainMenu::MainMenu(sf::Vector2f position, int height, int width,  sf::Font* font, GameController* game_controller_ptr) {
	this->position = position;
	this->game_controller_ptr = game_controller_ptr;
	SizeBox size_box(sf::Vector2f((height / 2) - 100, (width / 2) - 200),{200,100});
	widgets.push_back(
		std::make_unique<TextLabel>(sf::Vector2f((height / 2) - 100, (width / 2) - 200), font, L"�����", sf::Color::White, Orientation::Center, size_box.getCenter(),50));
	//dynamic_cast<TextLabel*>(widgets[0].get())->setCenter(shape.getGlobalBounds());
	widgets.push_back(
		std::make_unique<TextButton>(
			sf::Vector2f((height / 2) - 100, (width / 2) - 100),
			L"������", font,30,sf::Vector2f(200,100),
			sf::Color::White,
			sf::Color::Black));
	widgets.push_back(
		std::make_unique<TextButton>(
			sf::Vector2f((height / 2) - 100, (width / 2) + 50),
			L"�����", font, 30, sf::Vector2f(200, 100),
			sf::Color::White,
			sf::Color::Black));
			
	/*
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f((height / 2) -100, (width / 2) -200), L"�����", sf::Vector2f(200, 100),sf::Color::Black, sf::Color::White,60,font));
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f((height / 2) - 100, (width / 2) - 100), L"������", sf::Vector2f(200, 100)));
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f((height / 2) -100, (width / 2) + 50), L"�����", sf::Vector2f(200, 100)));
		*/

}
void MainMenu::update_input(sf::Vector2f mouse_position) {
	if (widgets[1]->getBounds().contains(mouse_position)) {
		(*game_controller_ptr).setGameState(GameState::Play);
		std::cout << "Start" << std::endl;

	}
	else if(widgets[2]->getBounds().contains(mouse_position)) {
		(*game_controller_ptr).setGameState(GameState::Close);
		std::cout << "Exit" << std::endl;
	}
	
}


/*
widgets.push_back(
std::make_unique<TextButton>(sf::Vector2f((height / 2) - 100, (width / 2) - 100), "Start", sf::Vector2f(100, 100)));
*/