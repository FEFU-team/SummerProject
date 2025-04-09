#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    sf::RectangleShape shape({ 100.f,100.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 100,100 });
    sf::Vector2i mousePos;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);


            if (shape.getGlobalBounds().contains(mousePosF)) {
                shape.setFillColor(sf::Color::Green);
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
