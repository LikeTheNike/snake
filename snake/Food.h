#pragma once

#include <SFML/Graphics.hpp>
#include "Drawhelper.h"


class Food
{
public:
	Food(sf::Vector2i startPosition)
	{
		position = startPosition;
	}

	void draw(DrawHelper& drawHelper)
	{
	}

	sf::Vector2i getPosition() const
	{
		return position;
	}

private:
	sf::Vector2i position;
};
