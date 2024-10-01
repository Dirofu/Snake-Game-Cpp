#include "MainMenuUI.h"

namespace SnakeGame
{
	void InitializeMainMenu(MainMenuUI& menu)
	{
		menu.startButton = Button(sf::Text(), menu.startText, ButtonType::Start);
		menu.settingsButton = Button(sf::Text(), menu.settingsText, ButtonType::Settings);
		menu.leaderboardButton = Button(sf::Text(), menu.leaderboardText, ButtonType::Leaderboard);
		menu.exitButton = Button(sf::Text(), menu.exitText, ButtonType::Exit);
		menu.selectedButton = menu.startButton;
	}
}