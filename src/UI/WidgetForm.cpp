#include "WidgetForm.h"



void WidgetForm::draw(sf::RenderTarget* window)
{
	for (int i = 0; i < widgets.size(); i++) {
		widgets[i]->draw(window);
	}
}

void WidgetForm::setPosition(sf::Vector2f new_position)
{
	this->position = position;
}
