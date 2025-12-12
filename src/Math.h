#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	static bool DidRectCollide(sf::IntRect rect1, sf::IntRect rect2);
};