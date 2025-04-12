// Copyright 2023 Your Name or Organization

#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }),
                                    "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setPosition({ 200, 400 });

    sf::CircleShape circle(200.f);
    sf::RectangleShape rec({ 100, 100 });
    circle.setRadius(100.f);

    sf::Vector2f p = { 100, 100 };
    circle.setPosition(p);
    circle.setPointCount(50);

    double velocity = 0.5;
    int unused_variable; //  Две пробела перед комментарием

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

    return 0;
}
