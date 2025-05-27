
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
	sf::Text w_text(font);
	w_text.setFillColor(text_color);
	w_text.setString(text);
	w_text.setCharacterSize(text_size);
	// ѕримерно сделать центрирование текста
	w_text.setPosition({ position.x + 75,position.y + 25 });
	window->draw(shape);
	window->draw(w_text);
}

TextButton::TextButton(sf::Vector2f position, sf::String text,  sf::Font& font):Button(position,{100,100},sf::Color::White)
{
	this->position = position;
	this->font = font;
	this->text = text;

}

TextButton::TextButton(sf::Vector2f position, sf::String text, sf::Font& font, unsigned int text_size, sf::Vector2f button_size, sf::Color button_color, sf::Color text_color) :Button(position,button_size , button_color)
{
	this->position = position;
	this->font = font;
	this->text = text;
	this->text_size = text_size;
	this->text_color = text_color;

}


