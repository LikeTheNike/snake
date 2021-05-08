#pragma once

#include <SFML/Graphics.hpp>
#include <queue>

#include "Body.h"
#include "Direction.h"

class Snake
{
public:
	Snake(Direction startDirection, int startLength, sf::Vector2i startPosition)
	{
		for (int i = 0; i < startLength; ++i)
		{
			bodies.push(Body(startPosition + i * StepForDirection(startDirection)));
		}
		
		direction = startDirection;
	}

	void draw(sf::RenderTarget& target)
	{
	}

	void move(bool increaseLength)
	{
		bodies.push(Body(nextPosition()));
		bodies.pop();
	}

	sf::Vector2i getHead() const
	{
		return bodies.front().getPosition();
	}
	
	bool collidesWith(sf::Vector2i position) const
	{
	}

	sf::Vector2i nextPosition() const
	{
		return getHead() + StepForDirection(direction);
	}
	
private:
	Direction direction;
	std::queue<Body> bodies;
};
