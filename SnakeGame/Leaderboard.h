#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
	const int LEADERBOARD_MAX_PLAYERS = 10;
	const int LEADERBOARD_MAX_SCORE = 100;

	struct LeaderboardData
	{
		sf::String name;
		int score;
	};

	struct Leaderboard
	{
		LeaderboardData datas[LEADERBOARD_MAX_PLAYERS] = { };
	};

	const sf::String NAMES[] = { "James", "Jojo", "Ivan", "Sergo", "Dmitry", "DD", "Pupu", "Chad", "Solo", "Imposter", "jUster", "PacPac", "Shibu" };

	void InitializeLeaderboard(Leaderboard& board);

	void AddNewDataInLeaderboard(Leaderboard& board, sf::String name, int score);

	void SortLeaderboard(Leaderboard& board);

	void UpdatePlayerScoreInLeaderboard(Leaderboard& board, sf::String name, int score);

	sf::String GetLeaderboardText(sf::String startText, Leaderboard board);
}