#pragma once

namespace SnakeGame
{
	const int GAMERULE_INFINITYAPPLES = 1;
	const int GAMERULE_ACCELERATION = 2;

	struct GameMode
	{
		int mask = 0;
	};

	void InitializeGameMode(GameMode& mode);

	bool ChangeGameRuleStateByIndex(GameMode& mode, int index);

	bool CheckGameRuleActive(int mask, int index);
}