#ifndef SNAKE
#define SNAKE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
using namespace std;
using namespace sf;

const int WIDTH = 780;
const int HEIGHT = 540;
const int GRID_WIDTH = 13;
const int GRID_HEIGHT = 9;
const int GRID_SIZE = 60;

class Grid {
public:
    Grid(int width, int height, int size);
    void draw(sf::RenderWindow& window) const;

private:
    int m_width;
    int m_height;
    int m_size;
    std::vector<std::vector<sf::RectangleShape>> m_grid;
};

class Snake {
public:
    Snake(float x, float y, int size){
        add_case();
        time = 0.0f;
    }; 
    void draw(sf::RenderWindow& window); 
    void food();
    void add_case();
    void eating();
    void travel(sf::RenderWindow& window);
    void init();
    void check(sf::RenderWindow& window);
    void movement(Event &event, sf::RenderWindow& window);
    std::vector<sf::RectangleShape> tab;
    
private:
    
    sf::RectangleShape snake_food;
    sf::Clock mClock;
    int m_size;
    int time;
    int real_time;
    int win;
    bool left;
    bool right;
    bool up;
    bool down;
    int x;
    int y;
};

#endif 