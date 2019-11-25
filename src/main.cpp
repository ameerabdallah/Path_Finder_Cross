#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "SFML/Window/Mouse.hpp"
#include <iostream>

int main()
{
	int brushState = 0;
	int numOfStart = 0, numOfDest = 0;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello World");

	Grid grid(&window, 10, 10);

	std::printf("%d ", brushState);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case(sf::Event::Closed):
					window.close();
			case(sf::Event::KeyPressed): {
					if (event.key.code == sf::Keyboard::X) {
						brushState = 0;
						std::printf("%d ", brushState);
						break;
					}
					if (event.key.code == sf::Keyboard::W) {
						brushState = 1;
						std::printf("%d ", brushState);
						break;
					}
					if (event.key.code == sf::Keyboard::S) {
						brushState = 2;
						std::printf("%d ", brushState);
						break;
					}
					if (event.key.code == sf::Keyboard::D) {
						brushState = 3;
						std::printf("%d ", brushState);
						break;
					}
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
