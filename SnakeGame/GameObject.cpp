#include "GameObject.h"

namespace SnakeGame
{
	void UpdateSprite(GameObject& gameObject, sf::Texture& texture, sf::Sprite& sprite, float size)
	{
		sprite.setTexture(texture);
		sprite.setOrigin(GetSpriteOrigin(sprite, { 0.5f, 0.5f }));
		gameObject.scale = GetSpriteScale(sprite, { size , size });
		sprite.setScale(gameObject.scale);
	}
}