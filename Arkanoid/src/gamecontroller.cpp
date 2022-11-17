#include "gamecontroller.h"
#include <iostream>

void GameController::CheckInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //si la touche left du clavier est appuyée alors...
		{
			player.MoveLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //si la touche right du clavier est appuyée alors...
		{
			player.MoveRight();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			
		}

	}


}

void GameController::Update(sf::Time elapsedTime) {
	sf::RectangleShape playerShape = player.GetShape();
	const int x = playerShape.getPosition().x;
	const int barSize = playerShape.getSize().x;

	//if (x - barSize / 2 < 0) { //gauche
	//	player.Move(- x - barSize / 2);
	//}

	//if (x + barSize / 2 > window.getSize().x) { //droite
	//	player.Move(window.getSize().x - x + barSize / 2);
	//}
}

void GameController::Draw() {
	window.clear();
	player.Draw(window);
	window.display();
}

void GameController::Init() {
	window.create(sf::VideoMode(800, 600), "Blocks"); //Crée la window
	player = Player(sf::Vector2f(window.getSize().x / 2, 550));
}

void GameController::GameLoop() {
	sf::Clock clock;

	while (window.isOpen()) //tant que la fenêtre est ouverte, éxecute la boucle
	{
		CheckInput(); //si dans checkinput la fenêtre est fermé alors on sort de la boucle while
		Update(clock.restart()); 
		Draw();
	}
}



