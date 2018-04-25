#include <SFML/Graphics.hpp>
#include <vector>
#include "Homing.h"
#include <iostream>

using std::cout;

Homing::Homing(const sf::Vector2f &pos, const sf::Texture &texture, float speed, const sf::IntRect &rectangle) :
	Bullet(texture, rectangle, pos)
{
	target = sf::Vector2f(0, 0);
	this->speed = speed;
}

void Homing::update(sf::Time & delta) {

	

	//calculates the vector direction towards the target by subtracting self position from target position
	//then normalizing it to unit vector by dividing by own length
	//then multiplies direction by speed, and moves according to the result
	sf::Vector2f diff = target - getPosition();
	float diffLength = sqrt(diff.x * diff.x + diff.y * diff.y);
	sf::Vector2f dir = diff / diffLength;
	sf::Vector2f movement = speed * delta.asSeconds() * dir;
	move(movement.x, movement.y);

}

void Homing::setTarget(const sf::Vector2f &target) {
	this->target = target;
}

void Homing::setSpeed(int speed) {
	this->speed = speed;
}