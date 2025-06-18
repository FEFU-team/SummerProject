#include "../include/UI//End/End.h"
#include <UI/Text/TextLabel.h>
#include <UI/SizeBox.h>


End::End(sf::Vector2f position, sf::Font* font)
{
	SizeBox size_box(position);
	widgets.push_back(
		std::make_unique<TextLabel>(position, font, L"Конец", sf::Color::White,Orientation::Center,size_box.getCenter()));
}
void End::update_input(sf::Vector2f mouse_position)
{

}
