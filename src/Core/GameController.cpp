#include <Core/GameController.h>

void GameController::setGameState(GameState state)
{
	game_state = state;
}

GameState GameController::getGameState()
{
	return game_state;
}
