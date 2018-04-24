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
#include <iostream>
#include <random>
#include <cstdlib>
#include "bulletgroups.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{

	seedRand();

	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
	window.setFramerateLimit(60);
	int numFlankers = 50;

	vector<Homing> homings = createGroup<Homing>(numFlankers, sf::Vector2f(1, 1), 100);
	
	vector<int> randomFlankings;
	int i = 0;
	for (i = 0; i < numFlankers; i++) {
		int r = getRand() % 10000 - 5000;
		randomFlankings.push_back(r);
	}
	vector<PatternBullet> spiral = createGroup<PatternBullet>(numFlankers, sf::Vector2f(100,100), 1);
	
	Player player;
	sf::Time delta;
	sf::Clock clock;

	vector<Bullet*> allBullets;
	/*
	for (auto & s : spiral) {
		s.addSpiral();
	} */

	int iterations = 0;
	while (window.isOpen())
	{
		delta = clock.restart();

		//set targets for homing bullets
		//a bullet will, rather than always targetting the exact position of the player, will target
		//where the player is expected to be, based on current velocity, r seconds into the future
		if (iterations % 100 == 0) {
			for (auto & r : randomFlankings) {
				r = getRand() % 100000 - 50000;
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
		for (auto & homing : homings) {
			homing.update(delta);
		}

		player.Update(delta);

		window.clear();
		/*
		for (auto & s : spiral) {
			window.draw(s);
		} */
		for (auto & homing : homings) {
			window.draw(homing);
		}

		for (auto & homing : homings) {
			if (Collision::CircleTest(player.getSprite(), homing)) {
				window.close();
			}
		}
		player.Render(window);
		window.display();
		iterations++;
	}

	return 0;
}