#pragma once
#include <SFML/Graphics.hpp>
#include <WidgetForm.h>
#include<vector>
#include <Core/GameController.h>
class MainMenu:public WidgetForm {
public:
	void update_input(sf::Vector2f mouse_position) override;
	MainMenu(sf::Vector2f position, int height,int width,   sf::Font* font, GameController* game_controller_ptr,sf::Clock * timer);
private:
	GameController* game_controller_ptr;
	sf::Clock* timer;
};