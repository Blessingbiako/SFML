#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "box2d/b2_api.h"
#include <vector>
#include "enemy.h"
#include "missile.h"
#include "player.h"


int main()

{
	srand(time(NULL));


	sf::RenderWindow window(sf::VideoMode(1500, 800), "The Space Shooter Game");
	window.setFramerateLimit(30);

	//Init text
	sf::Font font;
	font.loadFromFile("data/Fonts/Dosis-Regular.ttf");

	// Init textures
	sf::Texture playerTex;
	playerTex.loadFromFile("data/Textures/ship.png");

	sf::Texture enemyTex;
	enemyTex.loadFromFile("data/Textures/enemy.png");

	sf::Texture missileTex;
	missileTex.loadFromFile("data/Textures/missile.png");

	//UI init
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setPosition(10.f, 10.f);

	sf::Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setPosition(100.f, window.getSize().y / 2);
	gameOverText.setString("GAME OVER!");

	// Player init
	int score = 0;
	Player player(&playerTex);
	int shootTimer = 20;
	sf::Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(12);
	hpText.setFillColor(sf::Color::Black);

	//Enemy init
	int enemySpawnTimer = 0;
	std::vector<Enemy> enemies;
	sf::Text eHpText;
	eHpText.setFont(font);
	eHpText.setCharacterSize(12);
	eHpText.setFillColor(sf::Color::Black);

	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}

		}

		if (player.HP > 0)
		{
			//Player
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				player.MoveUp();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				player.MoveLeft();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				player.MoveDown();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				player.MoveRight();

			hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
			hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));


			// Collision with window
			
			// Update player
			player.Update(window.getSize());

			//Update Controls
			if (shootTimer < 15)
				shootTimer++;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 15) //shooting
			{
				player.missiles.push_back(Missile(&missileTex, player.shape.getPosition()));
				shootTimer = 0; // reset timer
			}

			// Missiles
			for (size_t i = 0; i < player.missiles.size(); i++)
			{
				// Move
				player.missiles[i].shape.move(20.f, 0.f);

				// Out of window bounds.
				if (player.missiles[i].shape.getPosition().x > window.getSize().x)
				{
					player.missiles.erase(player.missiles.begin() + i);
					break;
				}

				//Enemy collision
				for (size_t k = 0; k < enemies.size(); k++)
				{
					if (player.missiles[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
					{
						if (enemies[k].HP <= 1)
						{
							score += enemies[k].HPMax;
							enemies.erase(enemies.begin() + k);
						}
						else
							enemies[k].HP--; //ENEMY TAKE DAMAGE

						player.missiles.erase(player.missiles.begin() + i);
						break;
					}
				}
			}

			//Enemy
			if (enemySpawnTimer < 25)
				enemySpawnTimer++;

			//enemy spawn
			if (enemySpawnTimer >= 25)
			{
				enemies.push_back(Enemy(&enemyTex, window.getSize()));
				enemySpawnTimer = 0; //reset timer
			}

			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].shape.move(-6.f, 0.f);

				if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
				{
					enemies.erase(enemies.begin() + i);
					break;
				}
				if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
				{
					enemies.erase(enemies.begin() + i);

					player.HP--; // PLAYER TAKE DAMAGE
					break;
				}
			}

			//UI Update
			scoreText.setString("Score: " + std::to_string(score));

			//Draw ===================================================================== DRAW
			window.clear(sf::Color::White);

			//Player.draw
			player.DrawPlayer(window);

			//Missiles
			for (size_t i = 0; i < player.missiles.size(); i++)
			{
				window.draw(player.missiles[i].shape);
			}

			//enemy
			for (size_t i = 0; i < enemies.size(); i++)
			{
				eHpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
				eHpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
				window.draw(eHpText);
				window.draw(enemies[i].shape);
			}


			//UI
			window.draw(scoreText);
			window.draw(hpText);

			if (player.HP <= 0)
				window.draw(gameOverText);


			window.display();
		}
	}
};