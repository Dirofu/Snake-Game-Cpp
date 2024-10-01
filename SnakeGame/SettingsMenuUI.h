#pragma once
#include "GameMenu.h"

namespace SnakeGame
{
	struct SettingsMenuUI : GameMenu
	{
		sf::Text title;

		sf::String titleText = "Settings";

		sf::String musicText = "Music: ";
		sf::String soundText = "Sound: ";
		sf::String speedText = "Speed: ";
		sf::String exitText = "exit";

		Button selectedButton = Button(sf::Text(), "", ButtonType::Null);

		Button musicButton = selectedButton;
		Button soundButton = selectedButton;
		Button speedButton = selectedButton;
		Button exitButton = selectedButton;

		Button& GetDownButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Music:
					return soundButton;

				case ButtonType::Sound:
					return speedButton;

				case ButtonType::Speed:
					return exitButton;

				case ButtonType::BackToMenu:
				default:
					return musicButton;
			}
		};

		Button& GetUpButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Music:
					return exitButton;

				case ButtonType::Sound:
					return musicButton;

				case ButtonType::Speed:
					return soundButton;

				case ButtonType::BackToMenu:
				default:
					return speedButton;
			}
		};

		Button& GetSelectedButton() override
		{
			switch (selectedButton.type)
			{
				case ButtonType::Music:
					return musicButton;
				case ButtonType::Sound:
					return soundButton;
				case ButtonType::Speed:
					return speedButton;
				case ButtonType::BackToMenu:
					return exitButton;

				default:
					return selectedButton;
			}
		}
	};

	void InitializeSettingsMenu(SettingsMenuUI& menu);
}