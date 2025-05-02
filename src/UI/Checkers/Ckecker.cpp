#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>
void Checker::draw(sf::RenderTarget* window)
{
	sf::RectangleShape shape({ 10,10 });
	window->draw(shape);
}
Checker::Checker()
{

}
Checker::~Checker()
{
}