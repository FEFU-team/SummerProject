#pragma once
#include <SFML/Graphics.hpp>
#include <WidgetForm.h>
#include<vector>
#include <Core/GameController.h>
class End :public WidgetForm {
public:
	// Унаследовано через WidgetForm
	void update_input(sf::Vector2f mouse_position) override;
	End(sf::Vector2f position, sf::Font* font, sf::String text,GameController* game_controller);
private:
	GameController* game_controller;
};