#pragma once
#include <SFML/Window/Keyboard.hpp>

namespace SnakeGame
{
	struct Settings
	{
		sf::Keyboard::Key moveUp = sf::Keyboard::W;
		sf::Keyboard::Key moveLeft = sf::Keyboard::A;
		sf::Keyboard::Key moveDown = sf::Keyboard::S;
		sf::Keyboard::Key moveRight = sf::Keyboard::D;
		sf::Keyboard::Key accept = sf::Keyboard::Return;
		sf::Keyboard::Key exit = sf::Keyboard::Escape;

		bool activeSound = true;
		bool activeMusic = true;

		int gameSpeed = 3;
		int maxSpeed = 10;
	};

	void UpdateSettings(Settings& settings);
}