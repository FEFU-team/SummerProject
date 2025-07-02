#pragma once
#include <SFML/Graphics.hpp>
#include <WidgetForm.h>
#include<vector>
#include <Core/GameController.h>
class Info :public WidgetForm {
public:

	Info(sf::Vector2f position,sf::Font* font, GameController* game_controller);
	// Унаследовано через WidgetForm
	void update_input(sf::Vector2f mouse_position) override;
	void update_info(sf::String inf, int seconds, int milliseconds);
	bool get_lose();
	void reset();
private:
	sf::String color_player;
	GameController* game_controller;
	bool lose = false;
	sf::String timer;
};