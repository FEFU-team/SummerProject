
#include "../include/UI//Info/Info.h"
#include <UI/Text/TextLabel.h>
#include <UI/Buttons/TextButton.h>
#include <UI/SizeBox.h>
#include <iostream>
Info::Info(sf::Vector2f position, sf::Font* font, GameController* game_controller)
{
	this->game_controller = game_controller;
	SizeBox size_box(position, { 100,100 });
	widgets.push_back(
		std::make_unique<TextLabel>(position,font,L"Состояние игры", sf::Color::White));
	widgets.push_back(
		std::make_unique<TextLabel>(sf::Vector2f(position.x, position.y + 100), font, L"Текущий ход", sf::Color::White));
	widgets.push_back(
		std::make_unique<TextLabel>(sf::Vector2f(position.x+200, position.y+100), font, color_player, sf::Color::White));
	widgets.push_back(
		std::make_unique<TextLabel>(sf::Vector2f(position.x, position.y + 200), font, L"Время", sf::Color::White));
	widgets.push_back(
		std::make_unique<TextLabel>(sf::Vector2f(position.x + 500, position.y + 200), font, timer, sf::Color::White));
	widgets.push_back(
		std::make_unique<TextButton>(
			sf::Vector2f(position.x+600, position.y),
			L"Сдаться", font, 30, sf::Vector2f(100, 100),
			sf::Color::Black,
			sf::Color::White));
	//widgets.push_back(
		//std::make_unique<TextLabel>(sf::Vector2f(position.x, position.y+200), font, L"Возможно нужно есть", sf::Color::White));
}

void Info::update_input(sf::Vector2f mouse_position)
{
	if (dynamic_cast<TextButton*>(widgets[5].get())->isPressed(mouse_position)) {
		game_controller->setGameState(GameState::End);
		lose = true;;
	}
}

void Info::update_info(sf::String inf, sf::String timer)
{
	this->color_player = inf;
	this->timer = timer;
	// Преобразование типов
	dynamic_cast<TextLabel*>(widgets[2].get())->setText(inf);
	dynamic_cast<TextLabel*>(widgets[4].get())->setText(timer);

}

bool Info::get_lose()
{
	return lose;
}

void Info::reset()
{
	lose = false;
}
