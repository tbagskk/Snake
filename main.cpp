#include "snake.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Le serpent qui se mort la queue");
    Grid grid(GRID_WIDTH, GRID_HEIGHT, GRID_SIZE);

    Snake snake(0, 0, GRID_SIZE);
    snake.init();
    snake.food();

    while (window.isOpen())
    {
        snake.travel(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    snake.movement(event, window);
                    break;
                default:
                    break;
            }
        }
        snake.check(window);
        window.clear();
        grid.draw(window);
        snake.draw(window);    
        window.display();
        window.setVerticalSyncEnabled(false);
    }
    return 0;
}
