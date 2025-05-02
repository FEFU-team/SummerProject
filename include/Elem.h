#include <SFML/Graphics.hpp>
class Elem{

protected:
	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Color color;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	void Draw(sf::RenderTarget* window);
private:


};