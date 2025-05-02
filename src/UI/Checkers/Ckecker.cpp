#include <SFML/Graphics.hpp>
#include <UI//Checkers/Checker.h>

void Checker::draw(sf::RenderTarget* window)
{
	sf::RectangleShape b({ 10,10 });
	window->draw(b);
}
Checker::Checker()
{

}
Checker::~Checker()
{
}