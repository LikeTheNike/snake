#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

#include "Drawhelper.h"
#include "Food.h"
#include "Snake.h"

class Game
{
public:
	Game(
		Direction direction,
		sf::Vector2i startPosition, 
		int startLength, 
		int foodCount, 
		sf::Vector2i startBoardSize)
		:
		snake(direction, startLength, startPosition)
	{
		boardSize = startBoardSize;

		for (int i = 0; i < foodCount; ++i)
		{
			generateNewFood();
		}
	}

	void draw(DrawHelper& drawHelper)
	{
	}
	
	void setSnakeDirection()
	{
	}

	void moveSnake()
	{
	}

private:
	std::vector<Food> foods;
	Snake snake;
	sf::Vector2i boardSize;
	
	void generateNewFood()
	{
		while (true)
		{
			Food food(sf::Vector2i(
				rand() % boardSize.x,
				rand() % boardSize.y));

			if (collidesWithAnything(food))
			{
				continue;
			}

			foods.push_back(food);
		}
	}

	bool collidesWithAnything(Food& food)
	{
		for (int i = 0; i < foods.size(); ++i)
		{
			if (foods[i].getPosition() == food.getPosition())
			{
				return true;
			}
		}
		
		return snake.collidesWith(food.getPosition());
	}
};
