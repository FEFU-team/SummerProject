
#include <UI/Text/TextLabel.h>
#include <iostream>

TextLabel::TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str) :text(*font ,text_str)
{
	this->position = position;
	text.setPosition(position);
}

void TextLabel::setCenter()
{
	sf::FloatRect textBounds = text.getGlobalBounds();
	position = textBounds.getCenter();

	std::cout <<"Button" << std::endl;
	std::cout << text.getLetterSpacing() << std::endl;
	std::cout << text.getCharacterSize() << std::endl;
	std::cout << text.getLineSpacing() << std::endl;
	std::cout << text.getOutlineThickness() << std::endl;

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
