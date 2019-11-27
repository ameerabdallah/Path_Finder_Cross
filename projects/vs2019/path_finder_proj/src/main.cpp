#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "SFML/Window/Mouse.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello World");

	Grid grid(&window, 16, 16);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed /*&& grid.is_running()*/)
			{
				int x = grid.get_mouse_pos_in_grid(sf::Mouse::getPosition(window)).x;
				int y = grid.get_mouse_pos_in_grid(sf::Mouse::getPosition(window)).y;

				grid.set_node_state(x, y);
			}
		}

		window.clear();
		grid.draw_grid();
		window.display();
	}

	return 0;
}
