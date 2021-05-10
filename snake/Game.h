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
		for (int i = 0; i < foods.size(); ++i)
		{
			foods[i].draw(drawHelper);
		}

		snake.draw(drawHelper);
	}
	
	void setSnakeDirection(Direction direction)
	{
		snake.setDirection(direction);
	}

	void moveSnake()
	{
		int foodIndex = getFoodAt(snake.nextPosition());

		if (foodIndex != -1)
		{
			foods.erase(foods.begin() + foodIndex);
		}

		snake.move(foodIndex != -1);

		if (foodIndex != -1)
		{
			generateNewFood();
		}
	}

private:
	std::vector<Food> foods;
	Snake snake;
	sf::Vector2i boardSize;

	int getFoodAt(sf::Vector2i position)
	{
		for (int i = 0; i < foods.size(); ++i)
		{
			if (foods[i].getPosition() == position)
			{
				return i;
			}
		}
		
		return -1;
	}
	
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
			break;
		}
	}

	bool collidesWithAnything(Food& food)
	{
		if (getFoodAt(food.getPosition()) != -1)
			return true;
		
		return snake.collidesWith(food.getPosition());
	}
};
