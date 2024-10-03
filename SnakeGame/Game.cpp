#include "Game.h"
#include "Resources.h"
#include <cassert>

namespace SnakeGame
{
	void InitializeGame(Game& game)
	{
		InitializeGameResources(game.resources);
		InitializeGameMode(game.mode);
		InitializeSound(game.sound, game.resources);
		InitializeUI(game.ui, game.resources.font, SCREEN_WIDTH, SCREEN_HEIGTH);
		InitializeLeaderboard(game.leaderboard);
		InitGameOverPanel(game.gameOverPanel);
		ReturnToMenu(game);
	}

	void InitGameOverPanel(sf::Sprite& gameOverPanel)
	{
		sf::Texture gameOverTexture = sf::Texture{};
		gameOverTexture.create(SCREEN_WIDTH, SCREEN_HEIGTH);
		gameOverPanel = sf::Sprite{};
		gameOverPanel.setTexture(gameOverTexture);
		gameOverPanel.setColor(sf::Color::Black);
	}

	void HandleInput(Game& game, sf::RenderWindow& window, sf::Event& event)
	{
		switch (game.currentGameState)
		{
			case GameState::MainMenu:
				HandleMenuInput(game, event, game.settings);
				return;

			case GameState::Leaderboard:
				HandleLeaderboardInput(game, event, game.settings);
				return;

			case GameState::Game:
				HandlePlayerInput(game.player, event, game.settings);
				break;

			case GameState::GameOverMenu:
				HandleGameOverInput(game, event, game.settings);
				return;

			case GameState::ExitDialog:
				HandleExitDialogInput(game, window, event, game.settings);
				return;

			case GameState::Settings:
				HandleSettingsInput(game, event, game.settings);
				return;
		}

	}

	void UpdateGameLoop(Game& game, float deltaTime)
	{
		switch (game.currentGameState)
		{
			case GameState::MainMenu:
			case GameState::Leaderboard:
			case GameState::GameOverMenu:
			case GameState::ExitDialog:
			case GameState::Settings:
				return;

			case GameState::Game:
				break;
		}

		UpdateUI(game.ui, game.countEatenApples);

		if (game.timeToNextStep > 0)
		{
			game.timeToNextStep -= deltaTime * game.settings.gameSpeed;
			return;
		}

		ChangePlayerPosition(game.player, deltaTime);

		game.timeToNextStep = game.timeToStep;
		game.player.canChangeDirection = true;

		if (CheckCollisionWithWindowBoarder(game.player.body[0].position, SEGMENT_SIZE, SCREEN_WIDTH, SCREEN_HEIGTH))
			EndGame(game);

		for (Apple& apple : game.apples)
		{
			if (CalculateDistance(game.player.body[0].position, apple.position) < SEGMENT_SIZE)
				if (CheckCircleCollisionBetweenObjects(game.player.body[0].position, SEGMENT_SIZE / 2, apple.position, SEGMENT_SIZE / 2))
					EatApple(game, apple);
		}

		for (int i = 1; i < game.player.body.size(); i++)
		{
			SnakeSegment segment = game.player.body[i];

			if (CalculateDistance(game.player.body[0].position, segment.position) < SEGMENT_SIZE)
				if (CheckRectangleCollisionBetweenObjects(game.player.body[0].position, segment.position, SEGMENT_SIZE / 2))
					EndGame(game);
		}
	}

	void EatApple(Game& game, Apple& apple)
	{
		bool isCorrectPosition = false;
		Position2D position = Position2D(-1.f, -1.f);
		game.countEatenApples++;
	
		if (game.settings.activeSound)
			PlaySound(game.sound.eatSound);

		AddNewSegment(game.player);

		while (!isCorrectPosition)
		{
			int segmentCounter = 1;
			position = GetRandomPosition2D(SCREEN_WIDTH, SCREEN_HEIGTH, SEGMENT_SIZE);
			
			for (int i = 1; i < game.player.body.size(); i++)
			{
				SnakeSegment segment = game.player.body[i];

				if (position != segment.position)
					segmentCounter++;

			}
			
			if (segmentCounter == game.player.body.size())
				isCorrectPosition = true;
		}

		UpdateApple(apple, game.resources.appleTexture, apple.sprite, position, SEGMENT_SIZE);
	}

	template <class T>
	void SelectButton(UI& ui, T& menu, Direction direction)
	{
		ChangeHighlightState(ui, menu.GetSelectedButton().text, false);

		switch (direction)
		{
			case Direction::Right:
				menu.selectedButton = menu.GetRightButton();
				break;
			case Direction::Up:
				menu.selectedButton = menu.GetUpButton();
				break;
			case Direction::Left:
				menu.selectedButton = menu.GetLeftButton();
				break;
			case Direction::Down:
				menu.selectedButton = menu.GetDownButton();
				break;
		}

		ChangeHighlightState(ui, menu.GetSelectedButton().text, true);
	}

	template <class T>
	void UseButton(Game& game, T& menu)
	{
		switch (menu.selectedButton.type)
		{
			case ButtonType::Start:
				RestartGame(game);
				break;

			case ButtonType::Leaderboard:
				OpenLeaderboard(game);
				break;

			case ButtonType::Settings:
				OpenSettings(game);
				break;

			case ButtonType::Exit:
				OpenExitDialog(game);
				break;

			case ButtonType::CloseGame:
				CloseGame(game);
				break;

			case ButtonType::BackToMenu:
				ReturnToMenu(game);
				break;

			case ButtonType::Music:
				InvertSettingState(game.settings.activeMusic, game.ui.settingsMenu.musicButton.text, game.ui.settingsMenu.musicText);
				UpdateSettingsMenu(game);
				break;

			case ButtonType::Sound:
				InvertSettingState(game.settings.activeSound, game.ui.settingsMenu.soundButton.text, game.ui.settingsMenu.soundText);
				UpdateSettingsMenu(game);
				break;

			case ButtonType::Speed:
				ChangeSpeed(game.settings.gameSpeed, game.settings.maxSpeed);
				UpdateSettingsMenu(game);
				break;

			case ButtonType::Null:
			default:
				break;
		}
	}

	void InvertSettingState(bool& state, sf::Text& text, sf::String baseText)
	{
		state = !state;
	}

	void ChangeSpeed(int& speed, int maxSpeed)
	{
		speed++;

		if (speed > maxSpeed)
			speed = 1;
	}

	void UpdateSettingsMenu(Game& game)
	{
		sf::String stateSound = game.settings.activeSound ? "+" : "-";
		SetText(game.ui.settingsMenu.soundButton.text, game.ui.settingsMenu.soundText + stateSound);

		stateSound = game.settings.activeMusic ? "+" : "-";
		SetText(game.ui.settingsMenu.musicButton.text, game.ui.settingsMenu.musicText + stateSound);

		SetText(game.ui.settingsMenu.speedButton.text, game.ui.settingsMenu.speedText + std::to_string(game.settings.gameSpeed));

		if (game.settings.activeMusic)
			PlaySoundRepeat(game.sound.backgroundSound);
		else
			StopPlayingSound(game.sound.backgroundSound);
	}

	void HandleMenuInput(Game& game, sf::Event& event, Settings settings)
	{
		if (event.key.code == settings.moveDown)
			SelectButton(game.ui, game.ui.mainMenu, Direction::Down);
		else if (event.key.code == settings.moveUp)
			SelectButton(game.ui, game.ui.mainMenu, Direction::Up);
		else if (event.key.code == settings.accept)
			UseButton(game, game.ui.mainMenu);
		else if (event.key.code == settings.exit)
			OpenExitDialog(game);
	}

	void HandleSettingsInput(Game& game, sf::Event& event, Settings& settings)
	{
		if (event.key.code == settings.moveUp)
			SelectButton(game.ui, game.ui.settingsMenu, Direction::Up);
		else if (event.key.code == settings.moveDown)
			SelectButton(game.ui, game.ui.settingsMenu, Direction::Down);
		else if (event.key.code == settings.accept)
			UseButton(game, game.ui.settingsMenu);
		else if (event.key.code == settings.exit)
			OpenExitDialog(game);
	}

	void HandleGameOverInput(Game& game, sf::Event& event, Settings settings)
	{
		if (event.key.code == settings.moveUp)
			SelectButton(game.ui, game.ui.gameOverMenu, Direction::Up);
		else if (event.key.code == settings.moveDown)
			SelectButton(game.ui, game.ui.gameOverMenu, Direction::Down);
		else if (event.key.code == settings.accept)
			UseButton(game, game.ui.gameOverMenu);
		else if (event.key.code == settings.exit)
			OpenExitDialog(game);
	}

	void HandleLeaderboardInput(Game& game, sf::Event& event, Settings settings)
	{
		if (event.key.code == settings.accept)
			UseButton(game, game.ui.leaderboardMenu);
		else if (event.key.code == settings.exit)
			OpenExitDialog(game);
	}

	void HandleExitDialogInput(Game& game, sf::RenderWindow& window, sf::Event& event, Settings settings)
	{
		if (event.key.code == settings.moveLeft)
			SelectButton(game.ui, game.ui.endGameMenu, Direction::Left);
		else if (event.key.code == settings.moveRight)
			SelectButton(game.ui, game.ui.endGameMenu, Direction::Right);
		else if (event.key.code == settings.accept)
			UseButton(game, game.ui.endGameMenu);
	}

	void EndGame(Game& game)
	{
		UpdatePlayerScoreInLeaderboard(game.leaderboard, game.player.name, game.countEatenApples);
		game.currentGameState = GameState::GameOverMenu;
		SetPlayerDeadStatus(game.player);
		StopPlayingSound(game.sound.backgroundSound);

		if (game.settings.activeSound)
			PlaySound(game.sound.dieSound);
	}

	void RestartGame(Game& game)
	{
		game.currentGameState = GameState::Game;
		game.countEatenApples = 0;

		float positionX = SCREEN_WIDTH / 2 - SEGMENT_SIZE / 2;
		float positionY = SCREEN_HEIGTH / 2 - SEGMENT_SIZE / 2;

		ResetPlayer(game.player, 
			game.resources.headTexture, 
			game.resources.bodyTexture, 
			INITIAL_SPEED, 
			Vector2D{ positionX, positionY },
			sf::Vector2f{ SEGMENT_SIZE, SEGMENT_SIZE });
		
		PlaceApplesOnScreen(game);

		if (game.settings.activeMusic)
			PlaySoundRepeat(game.sound.backgroundSound);
	}

	void ReturnToMenu(Game& game)
	{
		RestartGame(game);
		game.currentGameState = GameState::MainMenu;
	}

	void OpenLeaderboard(Game& game)
	{
		game.currentGameState = GameState::Leaderboard;

		sf::String text = GetLeaderboardText(game.ui.leaderboardMenu.leadersText, game.leaderboard);
		SetText(game.ui.leaderboardMenu.leaders, text);
	}

	void OpenSettings(Game& game)
	{
		game.currentGameState = GameState::Settings;
		UpdateSettingsMenu(game);
	}

	void OpenExitDialog(Game& game)
	{
		game.currentGameState = GameState::ExitDialog;
	}

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		switch (game.currentGameState)
		{
			case GameState::Game:
				for (Apple apple : game.apples)
					DrawApple(apple, window);

				DrawPlayer(game.player, window);
				break;

			case GameState::GameOverMenu:
				window.draw(game.gameOverPanel);
				break;
		}

		DrawUI(game.ui, window, game.player.isAlive, game.currentGameState);
	}

	void PlaceApplesOnScreen(Game& game)
	{
		Position2D position;

		for (int i = 0; i < APPLES_COUNT; i++)
		{
			position = GetRandomPosition2D(SCREEN_WIDTH, SCREEN_HEIGTH, SEGMENT_SIZE);
			UpdateApple(game.apples[i], game.resources.appleTexture, game.apples[i].sprite, position, SEGMENT_SIZE);
		}
	}

	void CloseGame(Game& game)
	{
		game.gameRun = false;
	}

	void DeinitializeGame(Game& game)
	{

	}
}