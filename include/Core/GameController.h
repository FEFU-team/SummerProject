#pragma once

enum class GameState { Init,Start,Play,End}; // ��������� ����
// 
class GameController {
public:
	void setGameState(GameState state);
	GameState getGameState();
private:
	// ��������� ����
	GameState game_state = GameState::Play;
};