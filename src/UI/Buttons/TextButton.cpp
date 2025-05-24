
#include <UI/Buttons/TextButton.h>

void TextButton::setTextSize(unsigned int size)
{

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

TextButton::TextButton(sf::Vector2f position, sf::String text,  sf::Vector2f size, sf::Color button_color, sf::Color text_color, unsigned int text_size):Button(position, size, button_color)
{
	this->position = position;
	font = sf::Font("../../../../assets/fonts/arialmt.ttf");
	this->text = text;
	shape.setSize(size);
	this->text_color = text_color;
	this->text_size = text_size;

}

