#pragma once
#include <SFML/Graphics.hpp>
#include <Widget.h>
#include<vector>
#include <Core/GameController.h>
class WidgetForm :public Widget {
public:
	// Обновляет позицию мышки для виджетов
	virtual void update_input(sf::Vector2f mouse_position) = 0;
	// Унаследовано через Widget


	//Отрисовка Виджетов 
	void draw(sf::RenderTarget* window) override;
	// Обновление позиции 
	void setPosition(sf::Vector2f new_position) override;
protected:
	// Вектор виджетов
	std::vector<std::unique_ptr<Widget>> widgets;
	

};