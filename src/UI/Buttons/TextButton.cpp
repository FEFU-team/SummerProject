
#include <UI/Buttons/TextButton.h>

void TextButton::setTextSize(unsigned int size)
{
	this->text_size = size;
}

std::string TextButton::getText()
{
	return text;
}

void TextButton::setText(std::string text)
{
	this->text = text;
}

void TextButton::setTextColor(sf::Color text_color)
{
	this->text_color = text_color;
}

void TextButton::draw(sf::RenderTarget* window)
{
	
	window->draw(shape);
	text_label.draw(window);
}

TextButton::TextButton(sf::Vector2f position, sf::String text,  sf::Font* font):Button(position,{100,100},sf::Color::White), text_label(position,font,text)
{
	this->position = position;
	this->text = text;
	
	

}

TextButton::TextButton(sf::Vector2f position, sf::String text, sf::Font* font, unsigned int text_size, sf::Vector2f button_size, sf::Color button_color, sf::Color text_color) :Button(position, button_size, button_color),text_label(position, font, text,text_color,Orientation::Center, getBounds().getCenter(),text_size)
{
	this->position = position;
	this->text = text;
	this->text_size = text_size;
	this->text_color = text_color;

	

}


