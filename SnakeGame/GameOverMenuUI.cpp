#include "GameOverMenuUI.h"

namespace SnakeGame
{
	void InitializeGameOverMenu(GameOverMenuUI& menu)
	{
		menu.restartButton = Button(sf::Text(), menu.restartText, ButtonType::Start);
		menu.leaderboardButton = Button(sf::Text(), menu.leaderboardText, ButtonType::Leaderboard);
		menu.backToMenuButton = Button(sf::Text(), menu.backToMenuText, ButtonType::BackToMenu);
		menu.selectedButton = menu.restartButton;
	}
}