#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace SnakeGame
{
	struct Resources
	{
		sf::Texture headTexture;
		sf::Texture bodyTexture;
		sf::Texture appleTexture;
		sf::SoundBuffer eatSound;
		sf::SoundBuffer dieSound;
		sf::SoundBuffer backgroundSound;
		sf::Font font;
	};

	void InitializeGameResources(Resources& resources);
}