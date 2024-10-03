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
	const int SCREEN_WIDTH = 1500;
	const int SCREEN_HEIGTH = 1200;
	const float SEGMENT_SIZE = 50.f;
	const int APPLES_COUNT = 1;
	const float INITIAL_SPEED = 100.f;
	const float ACCELERATION = 100.f;
}