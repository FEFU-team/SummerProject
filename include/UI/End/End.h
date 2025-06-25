#pragma once
#include <SFML/Graphics.hpp>
#include <WidgetForm.h>
#include<vector>
#include <Core/GameController.h>
#include <Core/GameBoardController.h>
class End :public WidgetForm {
public:
	// Унаследовано через WidgetForm
	void update_input(sf::Vector2f mouse_position) override;

	void update_end(const CheckersResult& result);
	End(sf::Vector2f position, sf::Font* font,GameController* game_controller);
private:
	GameController* game_controller;
	sf::String text;
};