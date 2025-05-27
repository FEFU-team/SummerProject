
#include "../include/UI//Info/Info.h"
#include <UI/Text/TextLabel.h>
#include <UI/Buttons/TextButton.h>
Info::Info(sf::Vector2f position, sf::Font font)
{
	widgets.push_back(
		std::make_unique<TextLabel>(position,font,text));
	widgets.push_back(
		std::make_unique<TextButton>(
			sf::Vector2f(position.x+100, position.y),
			L"Инфа", font, 60, sf::Vector2f(300, 100),
			sf::Color::White,
			sf::Color::Black));
}

void Info::update_input(sf::Vector2f mouse_position)
{

}

void Info::update_info(sf::String inf)
{
	this->text = inf;
	// Преобразование типов
	dynamic_cast<TextLabel*>(widgets[0].get())->setText(inf);

}
