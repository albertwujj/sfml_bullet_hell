#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "header.h"
#include "Homing.h"
#include "PatternBullet.h"
#include "Collision.h"
#include "GLOBAL_CONSTANTS.h"
#include "Player.h"
#include "Vector2d.h"

using std::cout;
using std::endl;
using std::vector;
using Iter = std::vector<int>::const_iterator;

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
	window.setFramerateLimit(60);

	sf::Texture orangeLaser;
	orangeLaser.loadFromFile("laser.png");
	
	vector<Homing> homings;
	int i = 0;
	for (i = 0; i < 100; i++) {
		Vector2f pos = Vector2f(rand() % 100 + 1, rand() % 100 + 1);
		homings.push_back(Homing(500.0, pos));
	}

	Player player;
	sf::Time time;
	sf::Clock clock;
	while (window.isOpen())
	{
	
		for (auto & homing : homings) {
			homing.setTarget(player.getPosition());
		}

		time = clock.restart();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
		for (auto & homing : homings) {
			homing.moveOnce(time);
		}
		
		player.Update(time);
		
		
		window.clear();
		for (auto homing : homings) {
			window.draw(homing);
		}

		for (auto & homing : homings) {
			if (!Collision::BoundingBoxTest(player.getSprite(), homing)) {
				player.Render(window);
			}
		}
		
		window.display();

	}

	return 0;
}