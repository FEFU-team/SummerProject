
#include"Elem.h"
class Checker :public Elem
{
	
public:
	int x = 0;
	void draw(sf::RenderTarget* window) override;
	Checker();
	~Checker();

private:

};