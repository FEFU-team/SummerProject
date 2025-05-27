
#include <UI/Text/TextLabel.h>

TextLabel::TextLabel(sf::Font font, sf::String text)
{
	this->text = text;
	this->font = font;

}

void TextLabel::draw(sf::RenderTarget* window)
{
	window->draw(sf::Text(font, text));
}

void TextLabel::setPosition(sf::Vector2f new_position)
{
	this->position = position;
}
