#pragma once
#include "Resources.h"
#include "Player.h"
#include "Apple.h"
#include "UI.h"
#include "Sound.h"
#include "GameMode.h"
#include "GameState.h"
#include "Leaderboard.h"

namespace SnakeGame
{
	struct Game
	{
		Player player;
		Apple apples[APPLES_COUNT];

		sf::Sprite gameOverPanel;

		Resources resources;
		UI ui;
		Sound sound;
		GameMode mode;
		GameState currentGameState;
		Leaderboard leaderboard;
		Settings settings;

		bool gameRun = true;

		int countEatenApples = 0;
		int applesOnScreen = 0;
		float timeToStep = 1.f;
		float timeToNextStep = 0.f;
	};

	void InitializeGame(Game& game);

	void InitGameOverPanel(sf::Sprite& gameOverPanel);

	void HandleInput(Game& game, sf::RenderWindow& window, sf::Event& event);

	void UpdateGameLoop(Game& game, float deltaTime);

	void EatApple(Game& game, Apple& apple);

	template <class T>
	void SelectButton(UI& ui, T& menu, Direction direction);

	template <class T>
	void UseButton(Game& game, T& menu);

	void InvertSettingState(bool& state, sf::Text& text, sf::String baseText);

	void ChangeSpeed(int& speed, int maxSpeed);

	void UpdateSettingsMenu(Game& game);

	void HandleMenuInput(Game& game, sf::Event& event, Settings settings);

	void HandleSettingsInput(Game& game, sf::Event& event, Settings& settings);

	void HandleGameOverInput(Game& game, sf::Event& event, Settings settings);

	void HandleLeaderboardInput(Game& game, sf::Event& event, Settings settings);

	void HandleExitDialogInput(Game& game, sf::RenderWindow& window, sf::Event& event, Settings settings);

	void EndGame(Game& game);

	void RestartGame(Game& game);

	void ReturnToMenu(Game& game);

	void OpenLeaderboard(Game& game);

	void OpenSettings(Game& game);

	void OpenExitDialog(Game& game);

	void DrawGame(Game& game, sf::RenderWindow& window);

	void PlaceApplesOnScreen(Game& game);

	void CloseGame(Game& game);

	void DeinitializeGame(Game& game);
}