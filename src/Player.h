#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
	sf::Texture texture;
	

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

	sf::RectangleShape boundingRectangle;
	int width = 64;
	int height = 64;
	sf::Vector2i size;
	float speed = .1;

public:
	
	sf::Sprite sprite;
	
	sf::IntRect boundingBox;
	Player();
	void Draw(sf::RenderWindow& window); // called every frame
	void Load(); // called on app start
	void Update(Enemy& enemy); // called every frame
};