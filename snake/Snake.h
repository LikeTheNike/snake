#pragma once

#include <SFML/Graphics.hpp>
#include <queue>

#include "Body.h"
#include "Direction.h"
#include "Drawhelper.h"

class Snake
{
public:
	Snake(Direction startDirection, int startLength, sf::Vector2i startPosition)
	{
		for (int i = 0; i < startLength; ++i)
		{
			bodies.push_front(Body(startPosition + i * StepForDirection(startDirection)));
		}
		
		direction = startDirection;
	}
	
	void draw(DrawHelper& drawHelper)
	{
		for (int i = 0; i < bodies.size(); ++i)
		{
			bodies[i].draw(drawHelper);
		}
	}

	void move(bool increaseLength)
	{
		bodies.push_front(Body(nextPosition()));

		if (increaseLength == false)
		{
			bodies.pop_back();
		}
	}

	sf::Vector2i getHead() const
	{
		return bodies.front().getPosition();
	}
	
	bool collidesWith(sf::Vector2i position) const
	{
		for (int i = 0; i < bodies.size(); ++i)
		{
			if (position == bodies[i].getPosition())
			{
				return true;
			}
		}

		return false;
	}

	sf::Vector2i nextPosition() const
	{
		return getHead() + StepForDirection(direction);
	}
	
	void setDirection(Direction newDirection)
	{
		if (IsDirectionInverted(direction, newDirection) == false)
		{
			direction = newDirection;
		}
	}


private:
	Direction direction;
	std::deque<Body> bodies;
};
