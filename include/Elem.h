#include <SFML/Graphics.hpp>
class Elem {
protected:
	sf::Vector2f position;
	int  scale;
	sf::Color color;
	sf::Texture texture;
public:
	//������� ��������� �������
	virtual void Draw(sf::RenderTarget* window);
	Elem();

};