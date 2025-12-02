#include "Player.h"
#include <iostream>
using namespace sf;

void Player::Draw()
{

}

void Player::Load()
{
    texture.loadFromFile("assets/player/textures/SaraFullSheet.png");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({ {64, 64}, {64, 64} }));
    sprite.scale(Vector2f(2, 2));
    sprite.setPosition(Vector2f(100, 100));
}

void Player::Update()
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
}

void Player::Initialize()
{
}


