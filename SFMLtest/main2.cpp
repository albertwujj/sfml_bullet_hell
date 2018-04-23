#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Global_Constants.hpp"

int main2()
{
	sf::RenderWindow window(sf::VideoMode(C::Window_Width, C::Window_Height), "Test");
	Player player;
	sf::Time time;
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		time = clock.restart();

		window.setFramerateLimit(500);

		player.Update(time);

		window.clear();
		player.Render(window);
		window.display();
	}

	return 0;
}