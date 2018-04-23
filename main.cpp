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
	
	sf::Texture orangeLaser;
	orangeLaser.loadFromFile("laser.png");
	Homing homing1 = Homing(orangeLaser);
	Player player;
	sf::Time time;
	sf::Clock clock;
	while (window.isOpen())
	{
		homing1.setTarget(player.getPosition());
		time = clock.restart();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
		player.Update(time);
		window.setFramerateLimit(20);
		
		
		homing1.moveOnce(5.0);
		
		window.clear();
		window.draw(homing1);
		player.Render(window);
		window.display();

	}

	return 0;
}