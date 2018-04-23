#include <SFML/Graphics.hpp>
#include <vector>
#include "Homing.h"
#include <iostream>

using std::cout;

Homing::Homing(const sf::Texture &texture, const sf::IntRect &rectangle, const sf::Vector2f &pos) :
	Bullet(texture, rectangle, pos)
{
	target = sf::Vector2f(0, 0);
}
void Homing::moveOnce(float speed) {

	//calculates the vector direction towards the target by subtracting self position from target position
	//then normalizing it to unit vector by dividing by own length
	sf::Vector2f diff = target - getPosition();
	float diffLength = sqrt(diff.x * diff.x + diff.y * diff.y);
	sf::Vector2f dir = diff / diffLength;
	sf::Vector2f movement = speed * dir;
	move(movement.x, movement.y);
	
}

void Homing::setTarget(const sf::Vector2f &target) {
	this->target = target;
}