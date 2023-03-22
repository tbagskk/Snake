#include "../Include/snake.h"

int main(int ac, char **av)
{
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, 580), "Le serpent qui se mort la queue");
    window.setPosition(sf::Vector2i(10, 50));
    Grid grid(GRID_WIDTH, GRID_HEIGHT, GRID_SIZE);
    Snake snake(0, 0, GRID_SIZE);
    if (snake.parsing(ac, av) == 0)
        return (0);
    snake.init(atoi(av[1]));
    snake.food();
    snake.speed_draw(window);
    char buffer[16];
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
        if (av[2][0] == 'y')
            grid.draw(window);
        snake.draw(window);    
        window.display();
        window.setVerticalSyncEnabled(false);
    }
    return 0;
}
