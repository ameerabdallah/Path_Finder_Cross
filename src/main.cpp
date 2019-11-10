#include <SFML/Graphics.hpp>
#include "Grid.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello World");

	Grid grid(&window, 10, 10);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		grid.draw_grid();
		window.display();
	}

	return 0;
}
