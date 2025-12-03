#include "Player.h"
#include "Enemy.h"
#include "Math.h"
#include <iostream>
using namespace sf;

Player::Player() : sprite(texture)
{

}

void Player::Draw(RenderWindow& window)
{
    window.draw(sprite);

    for (int i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

}

void Player::Load()
{
    texture.loadFromFile("assets/player/textures/SaraFullSheet.png");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({ {64, 64}, {64, 64} }));
    sprite.scale(Vector2f(2, 2));
    sprite.setPosition(Vector2f(100, 100));
}

void Player::Update(Enemy& enemy)
{
    // MOVING PLAYER
    Vector2f pos = sprite.getPosition();
    

    if (Keyboard::isKeyPressed(Keyboard::Key::D))
        sprite.setPosition(pos + Vector2f(1, 0));

    if (Keyboard::isKeyPressed(Keyboard::Key::A))
        sprite.setPosition(pos + Vector2f(-1, 0));

    if (Keyboard::isKeyPressed(Keyboard::Key::W))
        sprite.setPosition(pos + Vector2f(0, -1));

    if (Keyboard::isKeyPressed(Keyboard::Key::S))
        sprite.setPosition(pos + Vector2f(0, 1));

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
}


