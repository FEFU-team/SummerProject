#include <SFML/Graphics.hpp>
#include <Widget.h>

 sf::Vector2f Widget::getPosition() {
	 return position;
}
void Widget::setPosition(sf::Vector2f new_position) {
	position = new_position;
 }
void Widget::draw(sf::RenderTarget* window)
{
	
}
sf::FloatRect Widget::getBounds() {
	return sf::FloatRect();
}
sf::Color Widget::getColor()
{
	return color;
}
void Widget::setColor(sf::Color color)
{
	this->color = color;
}
Widget::Widget(){
}