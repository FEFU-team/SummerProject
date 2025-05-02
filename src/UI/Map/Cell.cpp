
#include <UI/Map/Cell.h>
#include <UI/Button.h>
#include <iostream>
Cell::Cell(sf::Vector2f positions):Button(positions) {
	
	shape.setSize({ 50,50 });
}
Cell::Cell():Button({0,0}) {

}