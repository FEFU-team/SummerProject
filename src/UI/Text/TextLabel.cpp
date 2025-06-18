
#include <UI/Text/TextLabel.h>
#include <iostream>

TextLabel::TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, Orientation orientation) :text(*font ,text_str)
{
	
	this->position = position;
	text.setCharacterSize(30);
	text.setPosition(position);
}

TextLabel::TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, sf::Color text_color, Orientation orientation) :text(*font, text_str)
{
	this->position = position;
	text.setPosition(position);
	text.setCharacterSize(30);
	text.setFillColor(text_color);

}

TextLabel::TextLabel(sf::Vector2f position, const sf::Font* font, sf::String text_str, sf::Color text_color, Orientation orientation, sf::Vector2f center) :text(*font, text_str)
{
	this->position = position;
	text.setFillColor(text_color);
	text.setCharacterSize(30);
	setCenter(center);
}

void TextLabel::setCenter(sf::Vector2f center)
{
	sf::FloatRect textBounds = text.getGlobalBounds();
	sf::FloatRect textBounds_l = text.getLocalBounds();
	
	sf::Vector2f  pos = textBounds.position;
	sf::Vector2f  pos2 = textBounds_l.getCenter();
	sf::Vector2f firstPos = text.findCharacterPos(0);
	sf::Vector2f lastPos = text.findCharacterPos(text.getString().getSize());

	center.x -= (textBounds.getCenter().x- firstPos.x);
	center.y -= (textBounds.getCenter().y);
	//text.setOrigin(textBounds.getCenter());
	//position = position - sf::Vector2f(textBounds.size.x/2, textBounds.size.y / 2);
	//text.setOrigin(center);
	text.setPosition(center);
}

void TextLabel::setText(sf::String text)
{
	this->text.setString(text);
}

void TextLabel::draw(sf::RenderTarget* window)
{
	window->draw(text);
	
}

void TextLabel::setPosition(sf::Vector2f new_position)
{
	this->position = position;
}
