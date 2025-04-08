#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            
           
            if (event->is<sf::Event::Closed>())
            {
                cout << "d" << endl;
                window.close();
            }
        }
        
        window.clear();
       
        window.display();
    }
}
