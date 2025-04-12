#include <SFML/Graphics.hpp>
int main()
{
    //#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    //#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setPosition({200,400});
    // define a circle with radius = 200
    sf::CircleShape circle(200.f);
    sf::RectangleShape rec({100,100});
    // change the radius to 40
    circle.setRadius(100.f);
    sf::Vector2f p = { 100,100 };
    circle.setPosition(p);
    double v  = .5;
    int x_xcxcxc_122;
    for (int i = 0; i <= 0; i++) {

    }
    // change the number of sides (points) to 100
    circle.setPointCount(50);
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        
        window.clear();
        window.draw(shape);
        window.draw(circle);
        window.draw(rec);
        window.display();
    }
}
