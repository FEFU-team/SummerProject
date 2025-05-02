#include <SFML/Graphics.hpp>
class Elem {
protected:
	//Позиция
	sf::Vector2f position;
	//Размер
	int  scale = 0;
	//Цвет
	sf::Color color;
	//Текстура
	sf::Texture texture;
public:
	//Функция отрисовки объекта
	virtual void Draw(sf::RenderTarget* window);
	Elem();

};