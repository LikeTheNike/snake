#pragma once

#include <SFML/Graphics.hpp>

class DrawHelper
{
public:
	DrawHelper(sf::RenderTarget& target, sf::Vector2f gridSize)
		:
		target(target),
		gridSize(gridSize)
	{
	}

	sf::RenderTarget& getTarget() const
	{
		return target;
	}

	const sf::Vector2f& getGridSize() const
	{
		return gridSize;
	}

private:
	sf::RenderTarget& target;
	sf::Vector2f gridSize;
};
