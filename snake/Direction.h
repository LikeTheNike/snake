#pragma once

#include <SFML/Graphics.hpp>

enum class Direction
{
	Up,
	Left,
	Down,
	Right
};

inline sf::Vector2i StepForDirection(Direction direction)
{
	switch (direction)
	{
	case Direction::Right:
		return sf::Vector2i(1, 0);

	case Direction::Down:
		return sf::Vector2i(0, 1);

	case Direction::Left:
		return sf::Vector2i(-1, 0);

	case Direction::Up:
		return sf::Vector2i(0, -1);

	}
}

inline bool IsDirectionInverted(Direction base, Direction direction)
{
	switch (base)
	{
	case Direction::Right:
		return direction == Direction::Left;
	
	case Direction::Down:
		return direction == Direction::Up;

	case Direction::Left:
		return direction == Direction::Right;

	case Direction::Up:
		return direction == Direction::Down;
	}
	
	return false;
}
