#include "Engine.h"
#include "D:\SFML\SFML_TEST\src\Main.hpp"
#include <iostream>
void Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }),
		"CMake SFML Project"); // Объект окна
	window->setFramerateLimit(144);
}

void Engine::Run()
{
    using namespace std;
    sf::RectangleShape shape({ 100.f,100.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 1,1 });
    sf::Vector2i mousePos;
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            sf::Vector2f mousePosF = window->mapPixelToCoords(mousePos);
            //mousePosF = { 0,0 };
            if (shape.getGlobalBounds().contains(mousePosF)) {

                if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mousePressed->button == sf::Mouse::Button::Right) {
                        cout << "right pressed" << endl;
                        shape.setFillColor(sf::Color::Blue);
                    }
                    else {
                        shape.setFillColor(sf::Color::Green);
                        cout << "Button pressed" << endl;
                    }

                }
            }
            else {
                shape.setFillColor(sf::Color::White);
            }

            if (event->is<sf::Event::Closed>())
            {
                cout << "d" << endl;
                window->close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
                    shape.move({ 0,-10 });
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
                    shape.move({ 10,0 });
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
                    shape.move({ 0,10 });
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
                    shape.move({ -10,0 });
                }

            }
        }
        window->clear();

        window->draw(shape);


        window->display();
    }
}

void Engine::End()
{
	if (window != nullptr) {
		delete window;
	}
}

Engine::Engine()
{
}

Engine::~Engine()
{
}
