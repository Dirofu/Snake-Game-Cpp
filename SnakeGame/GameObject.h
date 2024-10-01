#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace SnakeGame
{
	struct GameObject
	{
		sf::Vector2f scale;
		Position2D position;
		sf::Sprite sprite;
	};

	void UpdateSprite(GameObject& gameObject, sf::Texture& texture, sf::Sprite& sprite, float size);
}