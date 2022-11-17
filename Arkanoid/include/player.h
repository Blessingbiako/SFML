#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player() = default;
	Player(sf::Vector2f position);

	void MoveLeft();
	void MoveRight();
	void Draw(sf::RenderWindow& window);

	sf::RectangleShape GetShape() const { return _shape; }
	void Move(int x) { _shape.move(x, 0); }

private:
	sf::RectangleShape _shape;
};