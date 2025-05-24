#pragma once
#include <SFML/Graphics.hpp>
#include <Elem.h>
#include<vector>
#include <core/GameController.h>

class ResultGame :public Element {
public:
	void update_input(sf::Vector2f mouse_position);
	// Унаследовано через Element
	void draw(sf::RenderTarget* window) override;
	void setPosition(sf::Vector2f new_position) override;;
private:
	std::vector<std::unique_ptr<Element>> widgets;
	GameController* game_controller_ptr;
};