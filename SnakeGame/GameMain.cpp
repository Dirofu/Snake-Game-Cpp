#include "Constantes.h"
#include "Game.h"

int main()
{
	using namespace SnakeGame;

	int seed = (int)time(nullptr);
	srand(seed);

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGTH), "Diro Snake Game");

	Game game;
	InitializeGame(game);

	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	while (window.isOpen() && game.gameRun == true)
	{
		sf::sleep(sf::milliseconds(16));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
				HandleInput(game, window, event);
		}

		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		UpdateGameLoop(game, deltaTime);

		window.clear();
		DrawGame(game, window);
		window.display();
	}

	DeinitializeGame(game);

	return 0;
}
