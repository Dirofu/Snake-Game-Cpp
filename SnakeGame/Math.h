#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
	struct Vector2D
	{
		Vector2D(float vectorX = 0, float vectorY = 0)
		{
			x = vectorX;
			y = vectorY;
		}

		float x = 0;
		float y = 0;
	};

	typedef Vector2D Position2D;

	sf::Vector2f GetVector2fFrom2D(Vector2D vector);

	float CalculateDistance(Position2D obj1Position, Position2D obj2Position);

	bool CheckRectangleCollisionBetweenObjects(Position2D objPosition1, float sizeObj1, Position2D objPosition2, float sizeObj2);

	bool CheckCircleCollisionBetweenObjects(Position2D objPosition1, float objRadius1, Position2D objPosition2, float objRadius2);

	bool CheckCollisionWithWindowBoarder(Position2D objPosition, float objSize, float screenWidth, float screenHeigth);

	Position2D GetRandomPosition2D(float screenWidth, float screenHeigth);

	Position2D GetRandomPosition2D(float screenWidth, float screenHeigth, float gridSize);

	sf::Vector2f GetSpriteScale(const sf::Sprite& sprite, const Vector2D& desiredSize);

	sf::Vector2f GetSpriteOrigin(const sf::Sprite& sprite, const Vector2D& relativePosition);

	sf::Vector2f GetTextOrigin(sf::Text& text, const Vector2D& relativePosition);
}