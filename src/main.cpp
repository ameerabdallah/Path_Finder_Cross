#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
	std::vector<std::vector<sf::RectangleShape> > grid;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello World");

	sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(2.f);
	grid.resize(10);
	for (int i = 0; i < 10; i++)
	{
		grid[i].resize(10);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			rect.setPosition(sf::Vector2f(i * 50.f, j * 50.f));
			grid[i][j] = rect;
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				window.draw(grid[i][j]);
			}
		}
		window.display();
	}

	return 0;
}
