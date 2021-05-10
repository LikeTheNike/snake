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
		if (initialized == false)
		{
			rect.setFillColor(sf::Color::Red);
			rect.setPosition(sf::Vector2f(
				position.x * drawHelper.getGridSize().x,
				position.y * drawHelper.getGridSize().y));
			rect.setSize(drawHelper.getGridSize());

			initialized = true;
		}

		drawHelper.getTarget().draw(rect);
	}

	sf::Vector2i getPosition() const
	{
		return position;
	}

private:
	bool initialized = false;

	sf::Vector2i position;
	sf::RectangleShape rect;
};
