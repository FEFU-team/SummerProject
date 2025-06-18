#include <UI/SizeBox.h>

sf::FloatRect SizeBox::getGlobalBounds()
{
	return shape.getGlobalBounds();
}

sf::FloatRect SizeBox::getLocalBounds()
{
	return shape.getLocalBounds();
}

SizeBox::SizeBox(sf::Vector2f position, sf::Vector2f size)
{
	shape.setPosition(position);
	shape.setSize(size);
	
}
