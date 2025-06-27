
#pragma once
#include <SFML/Graphics.hpp>
class Ai {
public:
	std::pair<int, int> do_move();
	Ai();
private:
    int checker_value = 100; // стоимость простой шашки
    int king_value = 250; // стоимость короля
  

    

};