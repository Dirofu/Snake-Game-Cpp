#pragma once
#include "UIButtons.h"

namespace SnakeGame
{
	struct GameMenu
	{
		Button selectedButton = Button(sf::Text(), "", ButtonType::Null);

		virtual Button& GetDownButton()
		{
			return selectedButton;
		};

		virtual Button& GetUpButton()
		{
			return selectedButton;
		};

		virtual Button& GetLeftButton()
		{
			return selectedButton;
		};

		virtual Button& GetRightButton()
		{
			return selectedButton;
		};

		virtual Button& GetSelectedButton()
		{
			return selectedButton;
		}
	};
}