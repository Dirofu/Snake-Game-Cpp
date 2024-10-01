#include "UI.h"

namespace SnakeGame
{
	void InitializeUI(UI& ui, const sf::Font& font, float width, float heigth)
	{
		InitializeMainMenu(ui.mainMenu);
		SetUpText(ui.mainMenu.title, font, 100, sf::Color::Green, ui.mainMenu.titleText, { width / 2, 200 }, { .5f, 0.f });
		SetUpText(ui.mainMenu.startButton.text, font, 50, sf::Color::Red, ui.mainMenu.startText, { width / 2, heigth / 2 }, { .5f, 0.f });
		SetUpText(ui.mainMenu.settingsButton.text, font, 50, sf::Color::White, ui.mainMenu.settingsText, { width / 2, heigth / 2 + 75}, { .5f, 0.f });
		SetUpText(ui.mainMenu.leaderboardButton.text, font, 50, sf::Color::White, ui.mainMenu.leaderboardText, { width / 2, heigth / 2 + 150}, { .5f, 0.f });
		SetUpText(ui.mainMenu.exitButton.text, font, 50, sf::Color::White, ui.mainMenu.exitText, { width / 2, heigth / 2 + 225}, { .5f, 0.f });

		SetUpText(ui.gameTip, font, 25, sf::Color::White, ui.gameTipText, { 0.f, 0.f }, { 0.f, 0.f });
		SetUpText(ui.applesCounter, font, 25, sf::Color::White, ui.applesCounterText, { 0.f, 30.f }, { 0.f, 0.f });

		InitializeGameOverMenu(ui.gameOverMenu);
		SetUpText(ui.gameOverMenu.title, font, 100, sf::Color::White, ui.gameOverMenu.titleText, { width / 2, 200 }, { .5f, .5f });
		SetUpText(ui.gameOverMenu.restartButton.text, font, 50, sf::Color::Red, ui.gameOverMenu.restartText, { width / 2, heigth / 2 + 75 }, { .5f, .5f });
		SetUpText(ui.gameOverMenu.leaderboardButton.text, font, 50, sf::Color::White, ui.gameOverMenu.leaderboardText, { width / 2, heigth / 2 + 150 }, { .5f, .5f });
		SetUpText(ui.gameOverMenu.backToMenuButton.text, font, 50, sf::Color::White, ui.gameOverMenu.backToMenuText, { width / 2, heigth / 2 + 225 }, { .5f, .5f });
		
		InitializeLeaderboardMenu(ui.leaderboardMenu);
		SetUpText(ui.leaderboardMenu.title, font, 100, sf::Color::Green, ui.leaderboardMenu.titleText, { width / 2, 100 }, { .5f, .5f });
		SetUpText(ui.leaderboardMenu.leaders, font, 70, sf::Color::White, ui.leaderboardMenu.leadersText, { width / 2 - 250, 200 }, { 0, 0 });
		SetUpText(ui.leaderboardMenu.backToMenuButton.text, font, 50, sf::Color::Red, ui.leaderboardMenu.backToMenuText, { width / 2, heigth - 100 }, { .5f, .5f });

		InitializeSettingsMenu(ui.settingsMenu);
		SetUpText(ui.settingsMenu.title, font, 100, sf::Color::Green, ui.settingsMenu.titleText, { width / 2, 100 }, { .5f, .5f });
		SetUpText(ui.settingsMenu.musicButton.text, font, 50, sf::Color::Red, ui.settingsMenu.musicText, { width / 2, heigth / 2 + 75 }, { .5f, .5f });
		SetUpText(ui.settingsMenu.soundButton.text, font, 50, sf::Color::White, ui.settingsMenu.soundText, { width / 2, heigth / 2 + 150 }, { .5f, .5f });
		SetUpText(ui.settingsMenu.speedButton.text, font, 50, sf::Color::White, ui.settingsMenu.speedText, { width / 2, heigth / 2 + 225 }, { .5f, .5f });
		SetUpText(ui.settingsMenu.exitButton.text, font, 50, sf::Color::White, ui.settingsMenu.exitText, { width / 2, heigth / 2 + 350 }, { .5f, .5f });


		InitializeEndGameMenu(ui.endGameMenu);
		SetUpText(ui.endGameMenu.title, font, 50, sf::Color::White, ui.endGameMenu.titleText, { width / 2, heigth / 2 }, { .5f, .5f });
		SetUpText(ui.endGameMenu.yesButton.text, font, 30, sf::Color::White, ui.endGameMenu.yesText, { width / 2 - 45, heigth / 2 + 45}, { .5f, .5f });
		SetUpText(ui.endGameMenu.noButton.text, font, 30, sf::Color::Red, ui.endGameMenu.noText, { width / 2 + 45, heigth / 2 + 45}, { .5f, .5f });
	}

	void ChangeHighlightState(UI& ui, sf::Text& text, bool state)
	{
		SetColor(text, state ? ui.selectedColor : ui.unselectedColor);
	}

	void UpdateUI(UI& ui, int eatenApples)
	{
		SetText(ui.applesCounter, ui.applesCounterText + std::to_string(eatenApples));
	}

	void SetText(sf::Text& text, sf::String string)
	{
		text.setString(string);
	}

	void SetColor(sf::Text& text, sf::Color color)
	{
		text.setFillColor(color);
	}

	void SetUpText(sf::Text& obj, const sf::Font& font, int characterSize, const sf::Color color, sf::String& text, sf::Vector2f position, Vector2D origin)
	{
		obj.setFont(font);
		obj.setCharacterSize(characterSize);
		obj.setFillColor(color);
		obj.setString(text);
		obj.setOrigin(GetTextOrigin(obj, origin));
		obj.setPosition(position);
	}

	void DrawUI(UI& ui, sf::RenderWindow& window, bool isPlayerAlive, GameState gameState)
	{
		switch (gameState)
		{
		case GameState::MainMenu:
			window.draw(ui.mainMenu.title);
			window.draw(ui.mainMenu.startButton.text);
			window.draw(ui.mainMenu.settingsButton.text);
			window.draw(ui.mainMenu.leaderboardButton.text);
			window.draw(ui.mainMenu.exitButton.text);
			break;

		case GameState::Game:
			window.draw(ui.gameTip);
			window.draw(ui.applesCounter);
			break;

		case GameState::GameOverMenu:
			window.draw(ui.gameOverMenu.title);
			window.draw(ui.gameOverMenu.restartButton.text);
			window.draw(ui.gameOverMenu.leaderboardButton.text);
			window.draw(ui.gameOverMenu.backToMenuButton.text);
			break;

		case GameState::Leaderboard:
			window.draw(ui.leaderboardMenu.title);
			window.draw(ui.leaderboardMenu.leaders);
			window.draw(ui.leaderboardMenu.backToMenuButton.text);
			break;

		case GameState::Settings:
			window.draw(ui.settingsMenu.title);
			window.draw(ui.settingsMenu.musicButton.text);
			window.draw(ui.settingsMenu.soundButton.text);
			window.draw(ui.settingsMenu.speedButton.text);
			window.draw(ui.settingsMenu.exitButton.text);
			break;

		case GameState::ExitDialog:
			window.draw(ui.endGameMenu.title);
			window.draw(ui.endGameMenu.yesButton.text);
			window.draw(ui.endGameMenu.noButton.text);
			break;
		}
	}
}