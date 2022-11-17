#pragma once
#include <SFML/Graphics/Sprite.hpp>

class Missile

{
public:
	sf::Sprite shape;

	Missile(sf::Texture* texture, sf::Vector2f pos);

	void DrawMissiles();

	~Missile() {}

};