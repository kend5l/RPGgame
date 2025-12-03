#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture texture;

public:

	sf::Sprite sprite;
	Enemy();
	void Draw(sf::RenderWindow& window); // called every frame
	void Load(); // called on app start
	void Update(); // called every frame
};