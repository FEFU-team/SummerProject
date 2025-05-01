#pragma once
#include<string>
#include <SFML/Graphics.hpp>
class Button {
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape shape;

public:
	unsigned  int getKey();
	void Pressed();
	bool IsPressed(sf::Vector2f mouse_position_f);
	void Draw(sf::RenderTarget* window);
	Button(sf::Vector2f positions, sf::Vector2f  size_button = { 100,100 });
	~Button();
private:
	static inline unsigned index{};
	 unsigned  int key{};
};