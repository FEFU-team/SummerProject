#include <SFML/Graphics.hpp>
class Elem {
protected:
	//�������
	sf::Vector2f position;
	//������
	int  scale = 0;
	//����
	sf::Color color;
	//��������
	sf::Texture texture;
public:
	//������� ��������� �������
	virtual void Draw(sf::RenderTarget* window);
	Elem();

};