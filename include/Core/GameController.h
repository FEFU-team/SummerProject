#pragma once

enum class GameState { Init,Start, End }; // ��������� ����
// 
class GameController {
public:
	void setGameState(GameState state);
	GameState getGameState();
private:
	GameState game_state = GameState::Start;
};