#pragma once

#include <SFML/Graphics.hpp>

/*

Body body(na position);

*/

class Body
{
public:
	Body(sf::Vector2i startPosition)		
	{
		position = startPosition;
	}

	void draw(sf::RenderTarget& target)
	{
	}

	sf::Vector2i getPosition() const
	{
		return position;
	}

private:
	sf::Vector2i position;
};
