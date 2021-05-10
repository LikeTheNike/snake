#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Direction.h"
#include "Drawhelper.h"
#include "Game.h"

int main()
{
    sf::Vector2i boardSize = sf::Vector2i(30, 30);
    sf::Vector2f gridSize = sf::Vector2f(20, 20);
    Direction direction = Direction::Right;
    sf::Vector2i snakePosition = sf::Vector2i(10, 5);
    int snakeLength = 4;
    int foodCount = 3;
    int snakeTickRate = 150000;

    Game game(direction, snakePosition, snakeLength, foodCount, boardSize);

    sf::RenderWindow window(
        sf::VideoMode(boardSize.x * gridSize.x, boardSize.y * gridSize.y), "SFML works!");
    window.setVerticalSyncEnabled(true);
    DrawHelper drawHelper(window, gridSize);
        
    sf::Clock clock;
    int time = 0;
    
    while (window.isOpen())
    {
        time += clock.restart().asMicroseconds();

        while (time > snakeTickRate)
        {
            game.moveSnake();
            time -= snakeTickRate;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Key::W:
                        game.setSnakeDirection(Direction::Up);
                        break;
                    case sf::Keyboard::Key::A:
                        game.setSnakeDirection(Direction::Left);
                        break;
                    case sf::Keyboard::Key::S:
                        game.setSnakeDirection(Direction::Down);
                        break;
                    case sf::Keyboard::Key::D:
                        game.setSnakeDirection(Direction::Right);
                        break;
                }

                break;
            }
        }

        window.clear();
        game.draw(drawHelper);
        window.display();
    }

    return 0;
}
