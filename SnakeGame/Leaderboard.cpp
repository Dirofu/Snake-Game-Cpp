#include "Leaderboard.h"

namespace SnakeGame
{
	void InitializeLeaderboard(Leaderboard& board)
	{
		for (int i = 0; i < LEADERBOARD_MAX_PLAYERS; i++)
		{
			int nameId = rand() % (LEADERBOARD_MAX_PLAYERS - 1);
			int score = rand() % LEADERBOARD_MAX_SCORE;

			board.datas[i].score = score;
			board.datas[i].name = NAMES[nameId];
		}
		SortLeaderboard(board);
	}

	void AddNewDataInLeaderboard(Leaderboard& board, sf::String name, int score)
	{
		int newPlayerIndex = 0;
		SortLeaderboard(board);

		for (int i = LEADERBOARD_MAX_PLAYERS - 1; i >= 0; i--)
		{
			if (board.datas[i].score > score)
			{
				newPlayerIndex = i + 1;
				break;
			}
		}

		if (newPlayerIndex >= LEADERBOARD_MAX_PLAYERS)
			return;

		for (int i = LEADERBOARD_MAX_PLAYERS - 1; i > newPlayerIndex; i--)
		{
			board.datas[i] = board.datas[i - 1];
		}

		board.datas[newPlayerIndex].name = name;
		board.datas[newPlayerIndex].score = score;
	}

	void SortLeaderboard(Leaderboard& board)
	{
		for (int i = 0; i < LEADERBOARD_MAX_PLAYERS; i++)
		{
			for (int j = 0; j < LEADERBOARD_MAX_PLAYERS; j++)
			{
				if (j + 1 < LEADERBOARD_MAX_PLAYERS && board.datas[j].score < board.datas[j + 1].score)
				{
					LeaderboardData tempData = board.datas[j];
					board.datas[j] = board.datas[j + 1];
					board.datas[j + 1] = tempData;
				}
			}
		}
	}

	void UpdatePlayerScoreInLeaderboard(Leaderboard& board, sf::String name, int newScore)
	{
		for (int i = 0; i < LEADERBOARD_MAX_PLAYERS; i++)
		{
			if (board.datas[i].name == name)
			{
				if (board.datas[i].score < newScore)
				{
					board.datas[i].score = newScore;
					SortLeaderboard(board);
				}

				return;
			}
		}

		AddNewDataInLeaderboard(board, name, newScore);
	}

	sf::String GetLeaderboardText(sf::String startText, Leaderboard board)
	{
		sf::String text = startText;

		for (int i = 0; i < LEADERBOARD_MAX_PLAYERS; i++)
			text += std::to_string(i + 1) + " | " + board.datas[i].name + " | Score: " + std::to_string(board.datas[i].score) + "\n";

		return text;
	}
}