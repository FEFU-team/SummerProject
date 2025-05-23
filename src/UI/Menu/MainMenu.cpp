#include "..\include\UI\\Menu\MainMenu.h"
#include <iostream>
#include <UI/Buttons/TextButton.h>

#include <memory>
#include <UI/Map/Cell.h>
MainMenu::MainMenu(sf::Vector2f position) {
	this->position = position;
}
void MainMenu::draw(sf::RenderTarget* window)  {
	for (int i = 0; i < widgets.size(); i++) {
		widgets[i]->draw(window);
	}
}
void MainMenu::hello()
{
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f(100, 100), "hello"));
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f(200, 200), "word"));
	widgets.push_back(
		std::make_unique<TextButton>(sf::Vector2f(300, 300), "C++"));
	
	
	
}
