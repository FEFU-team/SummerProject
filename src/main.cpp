#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    auto window = sf::RenderWindow(sf::VideoMode({1080u, 1070u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    sf::RectangleShape shape({ 100.f,100.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 1,1 });
    sf::Vector2i mousePos;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
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
                window.close();
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
                    shape.move({ -10,0});
                }
                    
            }
        }
        window.clear();
        
        window.draw(shape);
        
        
        window.display();
    }
}
