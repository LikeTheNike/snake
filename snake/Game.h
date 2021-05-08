#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Food.h"
#include "Snake.h"

class Game
{
public:
	Game()
	{
	}

	void draw(sf::RenderTarget& target)
	{
	}

private:
	std::vector<Food> foods;
	Snake snake;
};
