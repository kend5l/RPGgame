#include "Enemy.h"
#include <iostream>
using namespace sf;

void Enemy::Draw()
{
}

void Enemy::Load()
{
    texture.loadFromFile("assets/enemy/textures/walk - sword.png");
    
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({ {0, 0}, {64,64} }));
    sprite.scale(Vector2f(2, 2));
    sprite.setPosition(Vector2f(1000, 700));
}

void Enemy::Update()
{
}

void Enemy::Initialize()
{
}
