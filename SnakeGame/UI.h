#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "GameState.h"
#include "MainMenuUI.h"
#include "EndGameMenuUI.h"
#include "LeaderboardMenuUI.h"
#include "GameOverMenuUI.h"
#include "SettingsMenuUI.h"

namespace SnakeGame
{
	struct UI
	{
		MainMenuUI mainMenu;
		EndGameMenuUI endGameMenu;
		LeaderboardMenuUI leaderboardMenu;
		GameOverMenuUI gameOverMenu;
		SettingsMenuUI settingsMenu;

		sf::Text gameTip;
		sf::Text applesCounter;

		sf::String gameTipText = "Arrows: change direction of player";
		sf::String applesCounterText = "Apples eaten: ";

		sf::Color selectedColor = sf::Color::Red;
		sf::Color unselectedColor = sf::Color::White;
	};

	void InitializeUI(UI& ui, const sf::Font& font, float width, float heigth);

	void ChangeHighlightState(UI& ui, sf::Text& text, bool state);

	void UpdateUI(UI& ui, int eatenApples);

	void SetText(sf::Text& text, sf::String string);

	void SetColor(sf::Text& text, sf::Color color);

	void SetUpText(sf::Text& obj, const sf::Font& font, int characterSize, const sf::Color color, sf::String& text, sf::Vector2f position, Vector2D origin);

	void DrawUI(UI& ui, sf::RenderWindow& window, bool isPlayerAlive, GameState gameState);
}