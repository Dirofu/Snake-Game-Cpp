#pragma once
#include "GameObject.h"

namespace SnakeGame
{
	struct Apple : GameObject
	{

	};

	void UpdateApple(Apple& apple, sf::Texture& texture, sf::Sprite& sprite, float screenWidth, float screenHeigth, float size, float gridSize);

	void DrawApple(Apple& apple, sf::RenderWindow& window);
}