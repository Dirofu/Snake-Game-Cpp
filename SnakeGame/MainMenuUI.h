#pragma once
#include "GameMenu.h"

namespace SnakeGame
{
	struct MainMenuUI : GameMenu
	{
		sf::Text title;

		sf::String titleText = "Snake Game";
		sf::String startText = "start";
		sf::String settingsText = "settings";
		sf::String leaderboardText = "leaderboard";
		sf::String exitText = "exit";
		
		Button selectedButton = Button(sf::Text(), "", ButtonType::Null);

		Button startButton = selectedButton;
		Button settingsButton = selectedButton;
		Button leaderboardButton = selectedButton;
		Button exitButton = selectedButton;

		Button& GetDownButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Start:
					return settingsButton;
				case ButtonType::Settings:
					return leaderboardButton;
				case ButtonType::Leaderboard:
					return exitButton;

				case ButtonType::Exit:
				default:
					return startButton;
			}
		};

		Button& GetUpButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Start:
					return exitButton;
				case ButtonType::Settings:
					return startButton;
				case ButtonType::Leaderboard:
					return settingsButton;

				case ButtonType::Exit:
				default:
					return leaderboardButton;
			}
		};

		Button& GetSelectedButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Start:
					return startButton;
				case ButtonType::Settings:
					return settingsButton;
				case ButtonType::Leaderboard:
					return leaderboardButton;
				case ButtonType::Exit:
					return exitButton;

				default:
					return selectedButton;
			}
		}
	};

	void InitializeMainMenu(MainMenuUI& menu);
}