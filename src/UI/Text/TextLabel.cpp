
#include <UI/Text/TextLabel.h>
#include <iostream>

TextLabel::TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str) :text(*font ,text_str)
{
	this->position = position;
	//text.setPosition(position);
	text.setCharacterSize(40);
}

void TextLabel::setCenter(sf::Vector2f center)
{
	sf::FloatRect textBounds = text.getGlobalBounds();
	sf::FloatRect textBounds_l = text.getLocalBounds();
	
	sf::Vector2f  pos = textBounds.position;
	sf::Vector2f  pos2 = textBounds_l.getCenter();
	center.x -= (textBounds.getCenter().x-text.getString().toWideString().length());
	center.y -= (textBounds.getCenter().y);
	//text.setOrigin(textBounds.getCenter());
	//position = position - sf::Vector2f(textBounds.size.x/2, textBounds.size.y / 2);
	//text.setOrigin(center);
	text.setPosition(center);
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
