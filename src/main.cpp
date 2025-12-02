#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
using namespace sf;

Vector2f NormalizeVector(Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    Vector2f normalizedVector;
    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;
    return normalizedVector;
}

int main()
{
    // -------------------------INITIALIZATION----------------------------------
    RenderWindow window(VideoMode({ 1920, 1080 }), "RPG Game");
    
    
    Player player;
    Enemy enemy;

    player.Initialize();
    enemy.Initialize();

    // ------------------------------LOAD------------------------------------------
    player.Load();
    enemy.Load();

    // BULLETS
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.5f;
    Vector2f bulletDirection;

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

        player.Update();
        enemy.Update();
       
       
        if (Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(RectangleShape(Vector2f(50, 25)));

            int i = bullets.size() - 1;
            bullets[i].setPosition(player.sprite.getPosition());
            
        }

        for (int i = 0; i < bullets.size(); i++)
        {
            bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }


        window.clear();
        player.Draw();
        window.draw(player.sprite);
        window.draw(enemy.sprite);

        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
      
        window.display();
    }

}
