#include <SFML/Graphics.hpp>
#include <Elem.h>

 sf::Vector2f Element::getPosition() {
	 return position;
}
void Element::setPosition(sf::Vector2f new_position) {
	position = new_position;
 }
void Element::draw(sf::RenderTarget* window)
{
	
}
sf::FloatRect Element::getBounds() {
	return sf::FloatRect();
}
sf::Color Element::getColor()
{
	return color;
}
void Element::setColor(sf::Color color)
{
	this->color = color;
}
Element::Element(){
}