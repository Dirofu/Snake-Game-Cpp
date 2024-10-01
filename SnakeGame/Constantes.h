#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
	enum class Direction
	{
		Right = 0,
		Up,
		Left,
		Down
	};

	const std::string RESOURCES_PATH = "Resources/";
	const int SCREEN_WIDTH = 2000;
	const int SCREEN_HEIGTH = 1200;
	const float PLAYER_SIZE = 50.f;
	const float APPLE_SIZE = 40.f;
	const int APPLES_COUNT = 20;
	const float INITIAL_SPEED = 100.f;
	const float ACCELERATION = 100.f;
}