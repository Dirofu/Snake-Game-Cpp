#pragma once
#include "Math.h"
#include <cstdlib>

namespace SnakeGame
{
	sf::Vector2f GetVector2fFrom2D(Vector2D vector)
	{
		return sf::Vector2f{ vector.x, vector.y };
	}

	float CalculateDistance(Position2D obj1Position, Position2D obj2Position)
	{
		return (float)sqrt(pow(obj2Position.x - obj1Position.x, 2) + pow(obj2Position.y - obj1Position.y, 2));
	}

	bool CheckRectangleCollisionBetweenObjects(Position2D objPosition1, Position2D objPosition2, float sectorSize)
	{
		float deltaX = (float)fabs(objPosition1.x - objPosition2.x);
		float deltaY = (float)fabs(objPosition1.y - objPosition2.y);

		return (deltaX <= (sectorSize + sectorSize) / 2.f &&
			deltaY <= (sectorSize + sectorSize) / 2.f);
	}

	bool CheckCircleCollisionBetweenObjects(Position2D objPosition1, float objRadius1, Position2D objPosition2, float objRadius2)
	{
		float squareDistance = (objPosition1.x - objPosition2.x) * (objPosition1.x - objPosition2.x) + (objPosition1.y - objPosition2.y) * (objPosition1.y - objPosition2.y);
		float squareRadiusSum = (objRadius1 + objRadius2) * (objRadius1 + objRadius2);

		return squareDistance <= squareRadiusSum;
	}


	bool CheckCollisionWithWindowBoarder(Position2D objPosition, float objSize, float screenWidth, float screenHeigth)
	{
		return (objPosition.x - objSize / 2.f < 0.f || objPosition.x + objSize / 2.f > screenWidth ||
			objPosition.y - objSize / 2.f < 0.f || objPosition.y + objSize / 2.f > screenHeigth);
	}

	Position2D GetRandomPosition2D(float screenWidth, float screenHeigth)
	{
		Position2D position;
		position.x = rand() / (float)RAND_MAX * screenWidth;
		position.y = rand() / (float)RAND_MAX * screenHeigth;
		return position;
	}

	Position2D GetRandomPosition2D(float screenWidth, float screenHeigth, float gridSize)
	{
		Position2D position;

		position.x = gridSize / 2 + (rand() % (int)((screenWidth - gridSize) / gridSize + 1)) * gridSize;
		position.y = gridSize / 2 + (rand() % (int)((screenHeigth - gridSize) / gridSize + 1)) * gridSize;

		return position;
	}

	sf::Vector2f GetSpriteScale(const sf::Sprite& sprite, const Vector2D& desiredSize)
	{
		const sf::Vector2u textureSize = sprite.getTexture()->getSize();
		const sf::Vector2f spriteScale = { desiredSize.x / textureSize.x, desiredSize.y / textureSize.y };
		return spriteScale;
	}

	sf::Vector2f GetSpriteOrigin(const sf::Sprite& sprite, const Vector2D& relativePosition)
	{
		const sf::Vector2u textureSize = sprite.getTexture()->getSize();
		return { relativePosition.x * textureSize.x, relativePosition.y * textureSize.y };
	}

	sf::Vector2f GetTextOrigin(sf::Text& text, const Vector2D& relativePosition)
	{
		sf::FloatRect textSize = text.getLocalBounds();
		return {
			(textSize.left + textSize.width) * relativePosition.x,
			(textSize.top + textSize.height) * relativePosition.y,
		};
	}
}