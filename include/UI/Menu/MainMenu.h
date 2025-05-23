#pragma once
#include <SFML/Graphics.hpp>
#include <Elem.h>
#include<vector>
class MainMenu:public Element {
public:
	void draw(sf::RenderTarget* window) override;
	void hello();
	MainMenu(sf::Vector2f position);
private:
	std::vector<std::unique_ptr<Element>> widgets;;
};