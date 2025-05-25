#pragma once
#include <SFML/Graphics.hpp>
#include <WidgetForm.h>
#include<vector>
#include <Core/GameController.h>
class MainMenu:public WidgetForm {
public:
	//void draw(sf::RenderTarget* window) override;
	void update_input(sf::Vector2f mouse_position) override;
	MainMenu(sf::Vector2f position, unsigned int height, unsigned int  width,GameController* game_controller_ptr);
	GameController* game_controller_ptr;
};