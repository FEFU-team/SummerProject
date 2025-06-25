#include "../include/UI//End/End.h"
#include <UI/Text/TextLabel.h>
#include <UI/SizeBox.h>
#include <UI/Buttons/TextButton.h>



void End::update_end( const CheckersResult &result)
{
	if (result == CheckersResult::WIN_WHITE) {
		dynamic_cast<TextLabel*>(widgets[1].get())->setText(L"�������� �������");
	}
	else if (result == CheckersResult::WIN_BLACK) {
		dynamic_cast<TextLabel*>(widgets[1].get())->setText(L"�������� ������");
	}
	else if (result == CheckersResult::PAT) {
		dynamic_cast<TextLabel*>(widgets[1].get())->setText(L"�����");
	}
	else if (result == CheckersResult::LOSE_BLACK) {
		dynamic_cast<TextLabel*>(widgets[1].get())->setText(L"������ ������");
	}
	else if (result == CheckersResult::LOSE_WHITE) {
		dynamic_cast<TextLabel*>(widgets[1].get())->setText(L"������ �������");
	}

}

End::End(sf::Vector2f position, sf::Font* font, GameController* game_controller)
{
	this->game_controller = game_controller;
	 widgets.push_back(
	std::make_unique<TextLabel>(sf::Vector2f(position.x,position.y-400), font, L"����� ����", sf::Color::White, Orientation::Center, 60));
	 widgets.push_back(
		 std::make_unique<TextLabel>(sf::Vector2f(position.x, position.y - 300), font, "", sf::Color::White, Orientation::Center, 60));
	 widgets.push_back(
		 std::make_unique<TextButton>(
			 sf::Vector2f(position.x-150, position.y-100),
			 L"������ ����� ���� ", font, 60, sf::Vector2f(300, 100),
			 sf::Color::Black,
			 sf::Color::White));
	 widgets.push_back(
		 std::make_unique<TextButton>(
			 sf::Vector2f(position.x - 150, position.y),
			 L"���������", font, 60, sf::Vector2f(300, 100),
			 sf::Color::Black,
			 sf::Color::White));
	//widgets.push_back(
		//std::make_unique<TextLabel>(position, font, L"�����", sf::Color::White, Orientation::Center, size_box.getCenter()));
	

	
}
void End::update_input(sf::Vector2f mouse_position)
{
	if (dynamic_cast<TextButton*>(widgets[3].get())->isPressed(mouse_position)) {
		game_controller->setGameState(GameState::Close);
	}
	else if (dynamic_cast<TextButton*>(widgets[2].get())->isPressed(mouse_position)) {
		game_controller->setGameState(GameState::Restart);
	}

}


