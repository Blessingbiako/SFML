#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <missile.h>
#include <SFML/Graphics/RenderWindow.hpp>

class Player
{


public:	
	
	sf::Sprite shape;
	sf::Texture* texture;

	int HP;
	int HPMax;

	std::vector<Missile> missiles;

	Player(sf::Texture* texture);

	~Player() {}

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Update(sf::Vector2u _winSize);
	void DrawPlayer(sf::RenderWindow& window);
	



};