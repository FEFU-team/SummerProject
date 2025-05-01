#pragma once
#include "D:\SFML\SFML_TEST\src\Main.hpp"
class Engine
{
protected:
	sf::RenderWindow* window;
public:
	void Init();
	void Run();

	void End();
	Engine();
	~Engine();

private:

};