#include "Enemy.h"
#include <iostream>
using namespace sf;

Enemy::Enemy() : sprite(texture)
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Blue);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Enemy::Draw(RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
}

void Enemy::Load()
{
    texture.loadFromFile("assets/enemy/textures/walk - sword.png");
    
    sprite.setTexture(texture);

    int XIndex = 0;
    int YIndex = 0;

    sprite.setTextureRect(sf::IntRect({ {XIndex * size.x, YIndex * size.y}, {size.x, size.y} }));
    sprite.scale(Vector2f(2, 2));
    boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    sprite.setPosition(Vector2f(1000, 700));
}

void Enemy::Update()
{
    boundingRectangle.setPosition(sprite.getPosition());

}


