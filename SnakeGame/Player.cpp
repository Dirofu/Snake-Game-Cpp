#include "Player.h"

namespace SnakeGame
{
	void HandlePlayerInput(Player& player, sf::Event& event, Settings& settings)
	{
		if (!player.canChangeDirection)
			return;

		if (event.key.code == settings.moveRight && player.body[0].direction != Direction::Left)
			player.body[0].direction = Direction::Right;
		else if (event.key.code == settings.moveUp && player.body[0].direction != Direction::Down)
			player.body[0].direction = Direction::Up;
		else if (event.key.code == settings.moveLeft && player.body[0].direction != Direction::Right)
			player.body[0].direction = Direction::Left;
		else if (event.key.code == settings.moveDown && player.body[0].direction != Direction::Up)
			player.body[0].direction = Direction::Down;

		player.canChangeDirection = false;
	}

	void ChangePlayerPosition(Player& player, float deltaTime)
	{
		for (int i = player.length - 1; i > 0; i--) 
		{
			player.body[i].position.x = player.body[i - 1].position.x;
			player.body[i].position.y = player.body[i - 1].position.y;
			player.body[i].direction = player.body[i - 1].direction;
		}

		switch (player.body[0].direction)
		{
			case Direction::Right:
				player.body[0].position.x += SEGMENT_SIZE;
				break;
			case Direction::Up:
				player.body[0].position.y -= SEGMENT_SIZE;
				break;
			case Direction::Left:
				player.body[0].position.x -= SEGMENT_SIZE;
				break;
			case Direction::Down:
				player.body[0].position.y += SEGMENT_SIZE;
				break;
		}
	}

	void ResetPlayer(Player& player, sf::Texture& headTexture, sf::Texture& bodyTexture, float speed, Vector2D startPosition, sf::Vector2f playerSize)
	{
		for (SnakeSegment oldSegment : player.body)
			player.body.pop_back();

		player.body = {};

		SnakeSegment headSegment = {};
		headSegment.position = startPosition;
		player.body.push_back(headSegment);

		SnakeSegment bodySegment = {};
		bodySegment.position = { startPosition.x - SEGMENT_SIZE, startPosition.y };
		player.body.push_back(bodySegment);

		player.speed = speed;
		player.body[0].direction = Direction::Right;
		player.isAlive = true;
		player.length = 2;

		UpdateSprite(player.body[0], headTexture, player.body[0].sprite, SEGMENT_SIZE);
		UpdateSprite(player.body[1], bodyTexture, player.body[1].sprite, SEGMENT_SIZE);
	}

	void SetPlayerDeadStatus(Player& player)
	{
		player.isAlive = false;
	}

	void AddAccelerationToPlayer(Player& player, float acceleration)
	{
		player.speed += acceleration;
	}

	void AddNewSegment(Player& player)
	{
		SnakeSegment newSegment = player.body[player.length - 1];
		player.body.push_back(newSegment);
		player.length++;
	}

	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		for (int i = 0; i < player.body.size(); i++)
		{
			SnakeSegment segment = player.body[i];

			segment.sprite.setPosition(segment.position.x, segment.position.y);

			switch (segment.direction)
			{
				case Direction::Up:
				{
					segment.sprite.setScale(segment.scale);
					segment.sprite.setRotation(270.f);
					break;
				}
				case Direction::Right:
				{
					segment.sprite.setScale(segment.scale);
					segment.sprite.setRotation(0.f);
					break;
				}
				case Direction::Down:
				{
					segment.sprite.setScale(segment.scale);
					segment.sprite.setRotation(90.f);
					break;
				}
				case Direction::Left:
				{
					segment.sprite.setScale(-segment.scale.x, segment.scale.y);
					segment.sprite.setRotation(0.f);
					break;
				}
			}

			window.draw(segment.sprite);
		}

	}
}