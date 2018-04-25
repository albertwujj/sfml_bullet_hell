#include <SFML/Graphics.hpp>
#include "PatternBullet.h"
#include <vector>
#include <iostream>
using std::cout;
using std::endl;

PatternBullet::PatternBullet(const sf::Vector2f &pos, const sf::Texture &texture, const sf::IntRect &rectangle) :
	Bullet(texture, rectangle, pos)
{
	sinceLast = 0;
	delay = 20;
}

//add a movement to the end of the vector of movements, each represented by a 2-element vector- the x and y direction
void PatternBullet::addMovement(const sf::Vector2f & movement) {
	this->movements.push_back(movement);
}

//if a certain number of seconds have passed since the last movement
//move according to the first movement in the vector, and delete it.
//then reset the sinceLast count to 0
void PatternBullet::update(sf::Time & delta) {
	sinceLast += delta.asMilliseconds();
	if (sinceLast > delay && movements.size() > 0) {
		sf::Vector2f movement = movements.front();
		movements.erase(movements.begin());
		move(movement.x, movement.y);
		sinceLast = 0;
	}


}


void PatternBullet::resetMovements() {
	movements.clear();
}

//adds a spiral pattern to the bullet by adding movements that alternate between
//going up, right, down, left (or backwards for counter-clockwise) by an increasing stepsize each time.
void PatternBullet::addSpiral(int initialDir, bool counterclockwise, int finalRadius, int initRadius) {
	int stepsize = initRadius;
	int i = 0;
	sf::Vector2f totalDist = sf::Vector2f(0, 0);
	i = 0;
	while (i < 10) {
		int dir = counterclockwise ? 3 - ((i + initialDir) % 4) : (i + initialDir) % 4;
		switch (dir) {
			//move up
		case 0:
			totalDist += sf::Vector2f(0, -stepsize);
			addMovement(sf::Vector2f(0, -stepsize));
			//move right
		case 1:
			totalDist += sf::Vector2f(stepsize, 0);
			addMovement(sf::Vector2f(stepsize, 0));
			//move left
		case 2:
			totalDist += sf::Vector2f(-stepsize, 0);
			addMovement(sf::Vector2f(-stepsize, 0));
			//move down
		case 3:
			totalDist += sf::Vector2f(0, stepsize);
			addMovement(sf::Vector2f(0, stepsize));
		}
		if ((int)sqrt(totalDist.x * totalDist.x + totalDist.y * totalDist.y) >= finalRadius) {
			break;
		}

		stepsize *= 1.03;
		i++;
	}
}