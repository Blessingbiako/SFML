#include "player.h"
#include "player.h"

Player::Player(sf::Vector2f position) {
	_shape.setSize(sf::Vector2f(100, 30));
	_shape.setFillColor(sf::Color::White);
	_shape.setOutlineColor(sf::Color::White);
	_shape.setOutlineThickness(2);
	_shape.setOrigin(_shape.getSize() / 2.f);
	_shape.setPosition(position);
}

	void Player::MoveLeft() {

		_shape.move(-10, 0);

	}
	void Player::MoveRight() {

		_shape.move(10, 0);

	}
	void Player::Draw(sf::RenderWindow& window) { //passe en réference (l'adresse de la window qui existe déja) pour dessiner dedans
		window.draw(_shape);
	}