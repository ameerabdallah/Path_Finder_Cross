#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "SFML/Window/Mouse.hpp"
#include <iostream>

int main()
{
	NodeState brushState = NodeState::open;
	int numOfStart = 0, numOfDest = 0;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello World");

	Grid grid(&window, 10, 10);

	grid.resize(12, 10);
	 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case(sf::Event::Closed):
					window.close();
			case(sf::Event::KeyPressed): {
				switch (event.key.code)
				{
				case(sf::Keyboard::X):
					brushState = NodeState::open;
					std::printf("%d ", brushState);
					break;
				case(sf::Keyboard::W):
					brushState = NodeState::wall;
					std::printf("%d ", brushState);
					break;
				case(sf::Keyboard::S):
					brushState = NodeState::start;
					std::printf("%d ", brushState);
					break;
				case(sf::Keyboard::D):
					brushState = NodeState::destination;
					std::printf("%d ", brushState);
					break;
				}
				break;
				}
			case(sf::Event::MouseButtonPressed/*&& grid.is_running()*/):
				{
					if (event.mouseButton.button == sf::Mouse::Left) {
						if (sf::Mouse::getPosition(window).x <= window.getSize().x && sf::Mouse::getPosition(window).y <= window.getSize().y) {
							int x = grid.get_mouse_pos_in_grid(sf::Mouse::getPosition(window)).x;
							int y = grid.get_mouse_pos_in_grid(sf::Mouse::getPosition(window)).y;
							/*if (numOfStart >= 1) {

							}*/
							grid.set_node_state(x, y, brushState);
						}
					}
				}
			}
		}

		window.clear();
		grid.draw_grid();
		window.display();
	}

	return 0;
}
