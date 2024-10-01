#pragma once
#include "GameMenu.h"

namespace SnakeGame
{
	struct EndGameMenuUI : GameMenu
	{
		sf::Text title;

		sf::String titleText = "Do you want quit?";
		sf::String yesText = "Yes";
		sf::String noText = "No";

		Button selectedButton = Button(sf::Text(), "", ButtonType::Null);

		Button yesButton = selectedButton;
		Button noButton = selectedButton;

		Button& GetLeftButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::BackToMenu:
					return yesButton;

				default:
					return selectedButton;
			}
		};

		Button& GetRightButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::CloseGame:
					return noButton;

				default:
					return selectedButton;
			}
		}


		Button& GetSelectedButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::CloseGame:
					return yesButton;

				default:
					return noButton;
			}
		}
	};

	void InitializeEndGameMenu(EndGameMenuUI& menu);
}