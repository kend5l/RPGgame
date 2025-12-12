#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture texture;
	int width = 64;
	int height = 64;
	sf::Vector2i size;
	sf::RectangleShape boundingRectangle;

public:
	sf::Sprite sprite;
	

	Enemy();
	void Draw(sf::RenderWindow& window); // called every frame
	void Load(); // called on app start
	void Update(); // called every frame
};