#include "Player.h"
#include <SFML/Graphics/Text.hpp>

Player::Player(sf::Texture* texture)
{
	this->HPMax = 10;
	this->HP = this->HPMax;

	this->texture = texture;
	this->shape.setTexture(*texture);

	this->shape.setScale(0.15f, 0.15f);
}

void Player::MoveUp() 
{
	shape.move(0.f, -10.f);
}

void Player::MoveDown() 
{
	shape.move(0.f, 10.f);
}

void Player::MoveLeft() 
{
	shape.move(-10.f, 0.f);
}

void Player::MoveRight()
{
	shape.move(10.f, 0.f);
}

void Player::Update(sf::Vector2u _winSize)
{

	if (shape.getPosition().x <= 0) // Left
		shape.setPosition(0.f, shape.getPosition().y);
	if (shape.getPosition().x >= _winSize.x - shape.getGlobalBounds().width) // Right
		shape.setPosition(_winSize.x - shape.getGlobalBounds().width, shape.getPosition().y);
	if (shape.getPosition().y <= 0) // Top
		shape.setPosition(shape.getPosition().x, 0.f);
	if (shape.getPosition().y >= _winSize.y - shape.getGlobalBounds().height) // Bottom
		shape.setPosition(shape.getPosition().x, _winSize.y - shape.getGlobalBounds().height);

}

void Player::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(shape);
}
