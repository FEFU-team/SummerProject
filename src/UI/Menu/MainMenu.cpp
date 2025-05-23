#include "..\include\UI\\Menu\MainMenu.h"
#include <iostream>
#include <UI/Buttons/TextButton.h>


MainMenu::MainMenu(sf::Vector2f position) {
	this->position = position;
}
void MainMenu::draw(sf::RenderTarget* window)  {
	for (int i = 0; i < widgets.size(); i++) {
		widgets[i].draw(window);
	}
}
void MainMenu::hello()
{
	widgets.push_back(TextButton({100,100},"hello"));
	widgets.push_back(TextButton({ 300,300 }, "word"));
	std::cout << "dd" << std::endl;
}
