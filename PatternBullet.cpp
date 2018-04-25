#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "PatternBullet.h"
#include <vector>
#include <iostream>
#include "vectorops.h"
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
//move according to the first position in the vector, and delete it.
//then reset the sinceLast count to 0
void PatternBullet::update(sf::Time & delta) {
	sinceLast += delta.asMilliseconds();
	if (sinceLast > delay && movements.size() > 0) {
		sf::Vector2f movement = movements.front();
		movements.pop_front();
		setPosition(movement);
		sinceLast = 0;
	}


}


void PatternBullet::resetMovements() {
	movements.clear();
}

//adds a spiral pattern to the bullet by repeatedly rotating and lengthening the displacement vector
// (and adding the result at each step to movements)
void PatternBullet::addSpiral(bool counterclockwise, int finalRadius, int initRadius) {

	sf::Vector2f initPos = getPosition();
	//the displacement from starting position
	sf::Vector2f currOffset = setLength(sf::Vector2f(1, 0), initRadius);

	sf::Transform r;
	r.rotate(5);

	while (getLength(currOffset) < finalRadius) {
		addMovement(currOffset + initPos);
		//rotate and lengthen the displacement vector
		currOffset = r.transformPoint(currOffset);
		currOffset = currOffset + setLength(currOffset, 0.1);
	}
}