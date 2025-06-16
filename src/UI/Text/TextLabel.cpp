
#include <UI/Text/TextLabel.h>

TextLabel::TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str) :text(*font ,text_str)
{
	this->position = position;
	text.setPosition(position);
}


void TextLabel::setText(sf::String text)
{
	
}

void TextLabel::draw(sf::RenderTarget* window)
{
	window->draw(text);
	
}

void TextLabel::setPosition(sf::Vector2f new_position)
{
	this->position = position;
}
