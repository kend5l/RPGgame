#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
using namespace sf;


int main()
{
    // -------------------------INITIALIZATION----------------------------------
    RenderWindow window(VideoMode({ 1920, 1080 }), "RPG Game");
    
    
    Player player;
    Enemy enemy;

    // ------------------------------LOAD------------------------------------------
    player.Load();
    enemy.Load();


    // GAME LOOP
    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
     // -------------------------------UPDATE----------------------------

        enemy.Update();
        player.Update(enemy);

        window.clear();

        player.Draw(window);
        enemy.Draw(window);

        window.display();
    }

}
