#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow window(sf::VideoMode(800, 600), "Blocks");

void DrawPainting() {
	sf::Color colorArray[20] = { sf::Color(114, 47, 55),sf::Color{ 136, 8, 8 }, sf::Color::Red, sf::Color{ 170, 74, 68 }, sf::Color{ 128, 0, 32}, sf::Color{ 255, 36, 0 },sf::Color{ 210, 4, 45 }};
	sf::RectangleShape block(sf::Vector2f(30, 30));

	std::cout << rand() % 5;

	block.setFillColor(colorArray[20]);
	block.setOutlineColor(sf::Color::White);
	block.setOutlineThickness(2);

	//const int magicNumber = rand() % 5;
	int x = 0;
	int y = 0;
	int step = block.getSize().x;

	for (int j = 0;j < 20;j++)
	{
		y = j * step;

		for (int i = 0;i < 26;i++)
		{
			const int magicNumber = rand() % 5;
			x = i * step;

			block.setFillColor(colorArray[magicNumber]);

			std::cout << "X=" << x << "Y=" << y << std::endl;

			block.setPosition(x, y);
			window.draw(block);

		}
	}
}

int main() {

	
	srand(time(NULL));
	
	while (window.isOpen())
	{
		

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					window.clear();
					DrawPainting();
					window.display();
				}
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}



		
	}
	
}
