#include "Sound.h"

namespace SnakeGame
{
	void InitializeSound(Sound& sound, Resources& resources)
	{
		sound.eatSound.setBuffer(resources.eatSound);
		sound.dieSound.setBuffer(resources.dieSound);
		sound.backgroundSound.setBuffer(resources.backgroundSound);
	}

	void PlaySound(sf::Sound& sound)
	{
		sound.play();
	}

	void PlaySoundRepeat(sf::Sound& sound)
	{
		sound.setLoop(true);
		sound.play();
	}

	void StopPlayingSound(sf::Sound& sound)
	{
		sound.setLoop(false);
		sound.stop();
	}
}