#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <list>
#include <vector>
#include "header.h"
#include "Bullet.h"
#include "Homing.h"
#include "Collision.h"
#include "GLOBAL_CONSTANTS.h"
#include "PatternBullet.h"
#include "Player.h"
#include "bulletgroups.h"
#include "Spiraler.h"

#include <iostream>
#include <random>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;

int main()
{

	seedRand();



	sf::RenderWindow window(sf::VideoMode(C::Window_Width, C::Window_Height), "SFML works!");
	window.setFramerateLimit(60);
	int numFlankers = 50;

	sf::Texture missile;
	if (!missile.loadFromFile("missle.png")) {
		missile = sf::Texture();
	}
	vector<Homing> homings = createGroup<Homing>(missile, numFlankers, sf::Vector2f(1, 1), 50);

	vector<int> randomFlankings;
	int i = 0;
	for (i = 0; i < numFlankers; i++) {
		int r = getRand() % 100000 - 10000;
		randomFlankings.push_back(r);
	}

	vector<PatternBullet> spiral = createGroup<PatternBullet>(missile, 1, sf::Vector2f(C::Window_Width / 2, C::Window_Height / 2), 10);
	std::list<PatternBullet> spiralList(spiral.begin(), spiral.end());
	Spiraler spiraler = Spiraler(spiralList);

	Player player;
	sf::Time delta;
	sf::Clock clock;
	vector<Bullet*> allBullets;
	for (auto & h : homings) {
		allBullets.push_back(&h);
	}
	for (auto & s : spiral) {
		s.addSpiral();
		allBullets.push_back(&s);
	}

	int iterations = 0;
	while (window.isOpen())
	{
		delta = clock.restart();
		cout << delta.asSeconds();
		//set targets for homing bullets
		//a bullet will, rather than always targetting the exact position of the player, will target
		//where the player is expected to be, based on current velocity, r seconds into the future 
		//r is random (and can be negative), in order to introduce randomness to bullet paths
		if (iterations % 50 == 0) {
			for (auto & r : randomFlankings) {
				r = getRand() % 100000 - 20000;
			}
		}
		int h = 0;
		for (auto & homing : homings) {
			homing.setTarget(player.getPosition() + (player.getVel() * (float)randomFlankings.at(h)));
			h++;
		}


		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		player.Update(delta);

		window.clear();


		for (Bullet *bullet : allBullets) {
			if (Collision::CircleTest(player.getSprite(), *bullet)) {
				window.close();
			}
			window.draw(*bullet);
			//with polymorphism, can call the correct update function depending on bullet type
			bullet->update(delta);
		}
		spiraler.updateAndRender(delta, window);
		player.Render(window);
		window.display();
		iterations++;
	}

	return 0;
}