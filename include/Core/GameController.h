#pragma once

enum class GameState { Init,Play,End, Settings,Close,Restart}; // ��������� ����
// ���������� ���������� ����
class GameController {
public:
	void setGameState(GameState state);
	GameState getGameState();
private:
	// ��������� ����
	GameState game_state = GameState::Init;
};