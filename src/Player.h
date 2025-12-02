#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture texture;

public:
	
	sf::Sprite sprite;
	
	void Draw(); // called every frame
	void Load(); // called on app start
	void Update(); // called every frame
	void Initialize(); // called on app start
};