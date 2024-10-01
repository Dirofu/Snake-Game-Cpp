#include "EndGameMenuUI.h"

namespace SnakeGame
{
	void InitializeEndGameMenu(EndGameMenuUI& menu)
	{
		menu.yesButton = Button(sf::Text(), menu.yesText, ButtonType::CloseGame);
		menu.noButton = Button(sf::Text(), menu.noText, ButtonType::BackToMenu);
		menu.selectedButton = menu.noButton;
	}
}