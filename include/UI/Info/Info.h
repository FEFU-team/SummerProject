#pragma once
#include <SFML/Graphics.hpp>
#include <WidgetForm.h>
#include<vector>
#include <Core/GameController.h>
class Info :public WidgetForm {
public:

	Info(sf::Vector2f position,sf::Font* font);
	// Унаследовано через WidgetForm
	void update_input(sf::Vector2f mouse_position) override;
	void update_info(sf::String inf);
private:
	sf::String text ;
};