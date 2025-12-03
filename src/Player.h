#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

public:
	
	sf::Sprite sprite;
	Player();
	void Draw(sf::RenderWindow& window); // called every frame
	void Load(); // called on app start
	void Update(Enemy& enemy); // called every frame
};