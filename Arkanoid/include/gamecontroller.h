#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"


class GameController

{
public:
	void CheckInput(); 
	void Update(sf::Time elapsedTime);
	void Draw();
	void Init();

	void GameLoop();

private:
	sf::RenderWindow window; //d�clare la variable
	Player player;
};