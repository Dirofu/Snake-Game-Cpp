#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
	enum class ButtonType
	{
		Null = 0,
		Start,
		Settings,
		Exit,
		Leaderboard,
		CloseGame,
		BackToMenu,
		Music,
		Sound,
		Speed,
	};

	struct Button
	{
		sf::Text text;
		sf::String string;
		ButtonType type;

		Button(sf::Text text, sf::String string, ButtonType type)
		{
			this->text = text;
			this->string = string;
			this->type = type;
		}
	};
}