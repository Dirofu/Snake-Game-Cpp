#include "SettingsMenuUI.h"

namespace SnakeGame
{
	void InitializeSettingsMenu(SettingsMenuUI& menu)
	{
		menu.musicButton = Button(sf::Text(), menu.musicText, ButtonType::Music);
		menu.soundButton = Button(sf::Text(), menu.soundText, ButtonType::Sound);
		menu.speedButton = Button(sf::Text(), menu.speedText, ButtonType::Speed);
		menu.exitButton = Button(sf::Text(), menu.exitText, ButtonType::BackToMenu);
		menu.selectedButton = menu.musicButton;
	}
}