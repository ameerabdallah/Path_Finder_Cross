#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "SFML/Window/Mouse.hpp"
#include <iostream>

int main()
{
	NodeState brushState = NodeState::open;
	sf::RenderWindow window(sf::VideoMode(500, 500), "Path Finder", sf::Style::Close);

	Grid grid(&window, 10, 10);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Event for if the window is closed
			if(event.type == sf::Event::Closed)
				window.close();

			// Event for if the window is resized
			if(event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}

			// Event for KeyPressed
			if(event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{

				case(sf::Keyboard::X): // X: Open

					brushState = NodeState::open;
					break;

				case(sf::Keyboard::W): // W: Wall

					brushState = NodeState::wall;
					break;

				case(sf::Keyboard::S): // S: Start

					brushState = NodeState::start;
					break;

				case(sf::Keyboard::D): // D: Destination

					brushState = NodeState::destination;
					break;


				case(sf::Keyboard::Down): // Down arrow: Make grid larger vertically (limit at 20

					// Upper Bounderies for y component
					if (grid.get_height() + 1 <= 20)
					{
						grid.resize(grid.get_width(), grid.get_height() + 1);
						window.setSize(sf::Vector2u(window.getSize().x, window.getSize().y + grid.get_rect_height()));
					}
					break;

				case(sf::Keyboard::Up): // Up arrow: Make grid smaller vertically (limit at 5)

					// Lower Bounderies for y component
					if (grid.get_height() - 1 >= 5)
					{
						grid.resize(grid.get_width(), grid.get_height() - 1);
						window.setSize(sf::Vector2u(window.getSize().x, window.getSize().y - grid.get_rect_height()));
					}

					break;
				case(sf::Keyboard::Right): // Right arrow: Make grid larger horizontally (limit at 30)

					// Upper Bounderies for x component
					if (grid.get_width() + 1 <= 30)
					{
						grid.resize(grid.get_width() + 1, grid.get_height());
						window.setSize(sf::Vector2u(window.getSize().x + grid.get_rect_width(), window.getSize().y));
					}

					break;
				case(sf::Keyboard::Left): // Left arrow: Make grid smaller horizontally (limit at 5)

					// Lower Bounderies for x component
					if (grid.get_width() - 1 >= 5)
					{
						grid.resize(grid.get_width() - 1, grid.get_height());
						window.setSize(sf::Vector2u(window.getSize().x - grid.get_rect_width(), window.getSize().y));
					}
					break;

				case(sf::Keyboard::Enter): // Enter/Return: start the program

					grid.run_a_star();
					break;
				}
			}

			// If the mouse button is pressed and it's not looking for the best path (edit mode)
			if(event.type == sf::Event::MouseButtonPressed && !grid.is_running())
			{

				if (event.mouseButton.button == sf::Mouse::Left) 
				{

					if (sf::Mouse::getPosition(window).x <= window.getSize().x && sf::Mouse::getPosition(window).y <= window.getSize().y) 
					{

						sf::Vector2i mouse_pos = grid.get_mouse_pos_in_grid(sf::Mouse::getPosition(window));
						int x = mouse_pos.x;
						int y = mouse_pos.y;
						grid.set_node_state(x, y, brushState); // Set to whatever brush state is

					}

				}

			}
			
		}

		// check_input(brushState, window, grid);
		window.clear();
		grid.draw_grid();
		window.display();
	}

	return 0;

}
