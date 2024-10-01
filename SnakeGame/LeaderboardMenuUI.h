#pragma once
#include "GameMenu.h"

namespace SnakeGame
{
	struct LeaderboardMenuUI : GameMenu
	{
		sf::Text title;
		sf::Text leaders;

		sf::String titleText = "Leaderboard";
		sf::String leadersText = "";
		sf::String backToMenuText = "Back to Menu";

		Button selectedButton = Button(sf::Text(), "", ButtonType::Null);
		Button backToMenuButton = selectedButton;

		Button& GetSelectedButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Null:
				default:
					return backToMenuButton;
			}
		}
	};

	void InitializeLeaderboardMenu(LeaderboardMenuUI& menu);
}