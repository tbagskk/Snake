#include "snake.h"

//fonction pour initialiser les differentes valeurs

void Snake::init()
{
    win = 0;
    left = false;
    right = true;
    up = false;
    down = false;
}

//fonction pour changer la direction du serpent en fonction de la touche presse

void Snake::movement(Event &event, sf::RenderWindow& window)
{
    if (event.key.code == sf::Keyboard::Left)
    {
        left = true;
        right = false;
        up = false;
        down = false;
    }  
    else if (event.key.code == sf::Keyboard::Right)
    {
        left = false;
        right = true;
        up = false;
        down = false;
    } 
    else if (event.key.code == sf::Keyboard::Up)
    {
        left = false;
        right = false;
        up = true;
        down = false;
    } 
    else if (event.key.code == sf::Keyboard::Down)
    {
        left = false;
        right = false;
        up = false;
        down = true;
    }
    
}

//fonction pour verifier les collisions avec les murs ou avec la queue du serpent

void Snake::check(sf::RenderWindow& window)
{
    int i = 2;
    if (tab[0].getPosition().x > 720 || tab[0].getPosition().x < 0)
        window.close();
    if (tab[0].getPosition().y > 480 || tab[0].getPosition().y < 0)
        window.close();
    while(i < tab.size())
    {
        if(tab[0].getPosition().x == tab[i].getPosition().x && tab[0].getPosition().y == tab[i].getPosition().y)
            window.close();
        i++;
    }
    
    
}