#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode({ 1080, 720 }), "RPG Game");
    Texture playerTexture;
    playerTexture.loadFromFile("assets/player/textures/Idle__001.png");
    Sprite playerSprite(playerTexture);

    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        Vector2f pos = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            playerSprite.setPosition(pos + Vector2f(1, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            playerSprite.setPosition(pos + Vector2f(-1, 0));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            playerSprite.setPosition(pos + Vector2f(0, -1));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            playerSprite.setPosition(pos + Vector2f(0, 1));
       

        window.clear();
        window.draw(playerSprite);
        window.display();
    }
}
