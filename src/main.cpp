
#include <SFML/Graphics.hpp>

int main() {

    // #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    // #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(300.f, 200.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
