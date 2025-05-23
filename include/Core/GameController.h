#pragma once

enum class GameState { Init,Start,Play,End}; // Состояние игры
// 
class GameController {
public:
	void setGameState(GameState state);
	GameState getGameState();
private:
	// Состояние игры
	GameState game_state = GameState::Play;
};