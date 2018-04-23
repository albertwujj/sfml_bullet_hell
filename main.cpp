#include <SFML/Graphics.hpp>
#include <iostream>
#include "header.h"
#include "Homing.h"
#include "PatternBullet.h"
#include "Collision.h"
#include "GLOBAL_CONSTANTS.h"
#include "Player.h"
#include "Vector2d.h"

using std::cout;
using std::endl;
int main()
{


	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");

	//Player player = Player();
	sf::Image ol;
	ol.loadFromFile("laser.png");
	sf::Texture orangeLaser;
	orangeLaser.loadFromImage(ol);
	Homing homing1 = Homing(orangeLaser);
	Player player = Player();
	sf::Clock clock;
	while (window.isOpen())
	{
		homing1.setTarget(player.getPosition());
		sf::Time elapsed1 = clock.getElapsedTime();
		clock.restart();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			player.Update(elapsed1);
		}
		//cout << homing1.getPosition().x << homing1.getPosition().y;
		player.Render(window);
		homing1.moveOnce(5.0);
		window.draw(homing1);
		window.clear();
		window.display();

	}

	return 0;
}