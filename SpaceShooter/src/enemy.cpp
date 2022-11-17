#include "Enemy.h"


	Enemy::Enemy(sf::Texture* texture, sf::Vector2u WindowSize)
	{
		this->HPMax = rand() % 3 + 1;
		this->HP = this->HPMax;

		this->shape.setTexture(*texture);

		this->shape.setScale(0.08f, 0.08f);

		this->shape.setPosition(WindowSize.x - this->shape.getGlobalBounds().width, rand() % (int)(WindowSize.y - this->shape.getGlobalBounds().height));

	}