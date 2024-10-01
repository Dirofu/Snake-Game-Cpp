#include "LeaderboardMenuUI.h"

namespace SnakeGame
{
	void InitializeLeaderboardMenu(LeaderboardMenuUI& menu)
	{
		menu.backToMenuButton = Button(sf::Text(), menu.backToMenuText, ButtonType::BackToMenu);
		menu.selectedButton = menu.backToMenuButton;
	}
}