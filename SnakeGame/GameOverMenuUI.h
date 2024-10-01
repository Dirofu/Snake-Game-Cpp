#pragma once
#include "GameMenu.h";

namespace SnakeGame
{
	struct GameOverMenuUI : GameMenu
	{
		sf::Text title;

		sf::String titleText = "Game over!";
		sf::String leaderboardText = "Leaderboard";
		sf::String backToMenuText = "Back to Menu";
		sf::String restartText = "Restart";

		Button selectedButton = Button(sf::Text(), "", ButtonType::Null);

		Button backToMenuButton = selectedButton;
		Button restartButton = selectedButton;
		Button leaderboardButton = selectedButton;

		Button& GetDownButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Start:
					return leaderboardButton;
				case ButtonType::BackToMenu:
					return restartButton;
				case ButtonType::Leaderboard:
					return backToMenuButton;

				default:
					return restartButton;
			}
		};

		Button& GetUpButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Start:
					return backToMenuButton;
				case ButtonType::BackToMenu:
					return leaderboardButton;
				case ButtonType::Leaderboard:
					return restartButton;

				default:
					return restartButton;
			}
		};

		Button& GetSelectedButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Start:
					return restartButton;
				case ButtonType::BackToMenu:
					return backToMenuButton;
				case ButtonType::Leaderboard:
					return leaderboardButton;

				default:
					return selectedButton;
			}
		}
	};

	void InitializeGameOverMenu(GameOverMenuUI& menu);
}