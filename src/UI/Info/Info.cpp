
#include "../include/UI//Info/Info.h"
#include <UI/Text/TextLabel.h>
#include <UI/Buttons/TextButton.h>
#include <UI/SizeBox.h>
Info::Info(sf::Vector2f position, sf::Font* font)
{
	SizeBox size_box(position, { 100,100 });
	widgets.push_back(
		std::make_unique<TextLabel>(position,font,L"Текущей игрок", sf::Color::White));
	widgets.push_back(
		std::make_unique<TextLabel>(sf::Vector2f(position.x + 100, position.y), font, "DDD", sf::Color::White));
	widgets.push_back(
		std::make_unique<TextButton>(
			sf::Vector2f(position.x+100, position.y+1000),
			L"Еуы", font, 60, sf::Vector2f(300, 100),
			sf::Color::White,
			sf::Color::Black));
}

void Info::update_input(sf::Vector2f mouse_position)
{

}

void Info::update_info(sf::String inf)
{
	this->color_player = inf;
	// Преобразование типов
	dynamic_cast<TextLabel*>(widgets[0].get())->setText(inf);

}
