#include "Apple.h"

namespace SnakeGame
{
	void UpdateApple(Apple& apple, sf::Texture& texture, sf::Sprite& sprite, Position2D newPosition, float size)
	{
		apple.position = newPosition;
		UpdateSprite(apple, texture, sprite, size);
		sprite.setPosition(GetVector2fFrom2D(apple.position));
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		window.draw(apple.sprite);
	}
}