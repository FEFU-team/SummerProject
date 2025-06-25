#pragma once

enum class GameState { Init,Play,End, Settings,Close,Restart}; // Состояние игры
// Управление состоянием игры
class GameController {
public:
	void setGameState(GameState state);
	GameState getGameState();
private:
	// Состояние игры
	GameState game_state = GameState::Init;
};