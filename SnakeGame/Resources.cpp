#include "Resources.h"
#include "Constantes.h"
#include <cassert>

namespace SnakeGame
{
	void InitializeGameResources(Resources& resources)
	{
		assert(resources.headTexture.loadFromFile(RESOURCES_PATH + "Snake_head.png"));
		assert(resources.bodyTexture.loadFromFile(RESOURCES_PATH + "Snake_Body.png"));
		assert(resources.appleTexture.loadFromFile(RESOURCES_PATH + "Apple.png"));
		assert(resources.eatSound.loadFromFile(RESOURCES_PATH + "Eat.wav"));
		assert(resources.dieSound.loadFromFile(RESOURCES_PATH + "lose.wav"));
		assert(resources.backgroundSound.loadFromFile(RESOURCES_PATH + "background.wav"));
		assert(resources.font.loadFromFile(RESOURCES_PATH + "Fonts\\Roboto-Medium.ttf"));
	}
}