#pragma once
#include <SFML/Audio.hpp>
#include "Resources.h"

namespace SnakeGame
{
	struct Sound
	{
		sf::Sound eatSound;
		sf::Sound dieSound;
		sf::Sound backgroundSound;
	};

	void InitializeSound(Sound& sound, Resources& resources);

	void PlaySound(sf::Sound& sound);

	void PlaySoundRepeat(sf::Sound& sound);

	void StopPlayingSound(sf::Sound& sound);
}