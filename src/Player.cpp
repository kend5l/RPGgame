#include "Player.h"
#include "Enemy.h"
#include "Math.h"
#include <iostream>
using namespace sf;

Player::Player() : sprite(texture)
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
   
}

void Player::Draw(RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    for (int i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

}

void Player::Load()
{
    // loading sara's full sprite sheet
    texture.loadFromFile("assets/player/textures/SaraFullSheet.png");
    sprite.setTexture(texture);
    // setting sara's base positioning
    sprite.setTextureRect(sf::IntRect({ { 0 * size.x, 2 * size.y}, {size.x, size.y} }));
    sprite.scale(Vector2f(2, 2));
   
    // setting a bounding rectangle for collision testing
    boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    // placing sara's starting position
    sprite.setPosition(Vector2f(100, 100));
}

void Player::Update(Enemy& enemy)
{
   
    Vector2f pos = sprite.getPosition();
    

    if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
        sprite.setTextureRect(sf::IntRect({ { 0 * size.x, 3 * size.y}, {size.x, size.y} }));
        sprite.setPosition(pos + Vector2f(speed, 0));
    }
        

    if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
        sprite.setTextureRect(sf::IntRect({ { size.x, size.y}, {size.x, size.y} }));
        sprite.setPosition(pos + Vector2f(-speed, 0));
    }
        
    if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        sprite.setTextureRect(sf::IntRect({ { 0 * size.x, 0 * size.y}, {size.x, size.y} }));
        sprite.setPosition(pos + Vector2f(0, -speed));
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
        sprite.setTextureRect(sf::IntRect({ { 0 * size.x, 2 * size.y}, {size.x, size.y} }));
        sprite.setPosition(pos + Vector2f(0, speed));

    }

    if (Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(RectangleShape(Vector2f(50, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());

    }

    for (int i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }

    boundingRectangle.setPosition(sprite.getPosition());

}


