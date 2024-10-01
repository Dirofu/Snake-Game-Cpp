#include "Apple.h"

namespace SnakeGame
{
	void UpdateApple(Apple& apple, sf::Texture& texture, sf::Sprite& sprite, float screenWidth, float screenHeigth, float size, float gridSize)
	{
		apple.position = GetRandomPosition2D(screenWidth, screenHeigth, gridSize);
		UpdateSprite(apple, texture, sprite, size);
		sprite.setPosition(GetVector2fFrom2D(apple.position));
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		window.draw(apple.sprite);
	}
}