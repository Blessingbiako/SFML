#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::Color colorArray[5] = { sf::Color::Cyan, sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Yellow };
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Blocks");
	sf::RectangleShape block(sf::Vector2f(30, 30));

	std::cout << rand() % 5;
	
	block.setFillColor(colorArray[2]);
	block.setOutlineColor(sf::Color::White);
	block.setOutlineThickness(2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//const int magicNumber = rand() % 5;
		int x = 0;
		int y = 0;
		int step = block.getSize().x;

		for (int j = 0;j < 20;j++)
		{
			y = j*step;
			
			for (int i = 0;i < 26;i++)
			{
				const int magicNumber = rand() % 5;
				x = i*step;
				block.setFillColor(colorArray[magicNumber]);
				std::cout << "X=" << x << "Y=" << y << std::endl;

				block.setPosition(x, y);
				window.draw(block);

			}
		}


		window.display();
	}
}