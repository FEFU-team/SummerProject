#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
#include<vector>
#include <Core/GameController.h>
class WidgetForm :public Widget {
public:
	virtual void update_input(sf::Vector2f mouse_position) = 0;
	// Унаследовано через Widget
	void draw(sf::RenderTarget* window) override;
	void setPosition(sf::Vector2f new_position) override;
protected:
	std::vector<std::unique_ptr<Widget>> widgets;
	

};