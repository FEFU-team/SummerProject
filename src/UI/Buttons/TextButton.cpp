
#include <UI/Buttons/TextButton.h>

void TextButton::draw(sf::RenderTarget* window)
{
	sf::Text w_text(font);
	w_text.setFillColor(sf::Color::Green);
	w_text.setString("Hello");
	w_text.setPosition(position);
	shape.setPosition(position);
	window->draw(shape);
	window->draw(w_text);
}

TextButton::TextButton(sf::Vector2f position, std::string text, sf::Color color):Button(position, { 100,100 }, color)
{
	this->position = position;
	font = sf::Font("../../../../assets/fonts/arialmt.ttf");

}

