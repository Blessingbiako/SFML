#pragma once
#include <SFML/Graphics/Sprite.hpp>

class Enemy
{
public:
	sf::Sprite shape;

	int HP;
	int HPMax;
	Enemy(sf::Texture* texture, sf::Vector2u WindowSize);

	~Enemy() {}
};