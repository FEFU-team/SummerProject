
#include <UI/Text/TextLabel.h>

TextLabel::TextLabel(sf::Vector2f position,sf::Font font, sf::String text)
{
	this->text = text;
	this->font = font;
	this->position = position;

}

void TextLabel::setText(sf::String text)
{
	this->text = text;
}

void TextLabel::draw(sf::RenderTarget* window)
{
	sf::Text w_text(font, text);
	w_text.setPosition(position);
	window->draw(w_text);
}

void TextLabel::setPosition(sf::Vector2f new_position)
{
	this->position = position;
}
