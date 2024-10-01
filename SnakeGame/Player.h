#pragma once
#include "Constantes.h"
#include "GameObject.h"
#include "Settings.h"

namespace SnakeGame
{
	struct SnakeSegment : GameObject
	{
		Direction direction = Direction::Right;
	};

	struct Player
	{
		sf::String name = "PLAYER";
		float speed = INITIAL_SPEED;
		bool isAlive = true;
		int length = 2;
		std::vector<SnakeSegment> body;
		bool canChangeDirection = true;
	};

	void HandlePlayerInput(Player& player, sf::Event& event, Settings& settings);

	void ChangePlayerPosition(Player& player, float deltaTime);

	void ResetPlayer(Player& player, sf::Texture& headTexture, sf::Texture& bodyTexture, float speed, Vector2D startPosition, sf::Vector2f playerSize);

	void SetPlayerDeadStatus(Player& player);

	void AddAccelerationToPlayer(Player& player, float acceleration);

	void AddNewSegment(Player& player);

	void DrawPlayer(Player& player, sf::RenderWindow& window);
}