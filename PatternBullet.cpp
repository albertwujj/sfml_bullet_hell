#include <SFML/Graphics.hpp>
#include "PatternBullet.h"
#include <vector>

PatternBullet::PatternBullet(const sf::Texture &texture, const sf::IntRect &rectangle, sf::Vector2f &pos) :
	Bullet(texture, rectangle, pos)
{
}

void PatternBullet::addMovement(sf::Vector2f & movement) {
	this->movements.push_back(movement);
}

void PatternBullet::moveOnce() {
	sf::Vector2f movement = movements.front();
	movements.erase(movements.begin());
	move(movement.x, movement.y);

}


void PatternBullet::resetMovements() {
	movements.clear();
}

void PatternBullet::addSpiral(int count, int radius, int growthFactor) {
	int i = 0;
	for (i = 0; i < count; i++) {

	}
}