#pragma once
#include <SFML/Graphics.hpp>
#include <Elem.h>
#include<vector>
#include <Core/GameController.h>
class MainMenu:public Element {
public:
	void update_input(sf::Vector2f mouse_position);
	void draw(sf::RenderTarget* window) override;
	MainMenu(sf::Vector2f position, unsigned int height, unsigned int  width,GameController* game_controller_ptr);
	// Унаследовано через Element
	void setPosition(sf::Vector2f new_position) override;
private:
	std::vector<std::unique_ptr<Element>> widgets;
	GameController* game_controller_ptr;

};