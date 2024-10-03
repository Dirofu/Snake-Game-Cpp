#pragma once
#include "GameObject.h"

namespace SnakeGame
{
	struct Apple : GameObject
	{

	};

	void UpdateApple(Apple& apple, sf::Texture& texture, sf::Sprite& sprite, Position2D newPosition, float size);

	void DrawApple(Apple& apple, sf::RenderWindow& window);
}