#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
#include<vector>
#include <Core/GameController.h>
class WidgetForm :public Widget {
public:
	virtual void update_input(sf::Vector2f mouse_position) = 0;
	void draw(sf::RenderTarget* window);
	// Унаследовано через Widget
	void setPosition(sf::Vector2f new_position) override;
private:
	std::vector<std::unique_ptr<Widget>> widgets;
	GameController* game_controller_ptr;

};