
#include <UI/Buttons/TextButton.h>

std::string TextButton::getText()
{
	return std::string();
}

void TextButton::setText(std::string text)
{
}

void TextButton::setTextColor(sf::Color text_color)
{
}

void TextButton::draw(sf::RenderTarget* window)
{
	sf::Text w_text(font);
	w_text.setFillColor(sf::Color::Black);
	w_text.setString(text);
	// Примерно 
	w_text.setPosition({ position.x + 20,position.y + 25 });
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(position);
	window->draw(shape);
	window->draw(w_text);
}

TextButton::TextButton(sf::Vector2f position, std::string text, sf::Color button_color):Button(position, { 100,100 }, button_color)
{
	this->position = position;
	font = sf::Font("../../../../assets/fonts/arialmt.ttf");
	this->text = text;

}

