#pragma once
#include <vector>
#include "Bullet.h"

using std::vector;

class PatternBullet : public Bullet
{
public:
	PatternBullet(const sf::Texture &texture = sf::Texture(), const sf::IntRect &rectangle = sf::IntRect(10, 10, 10, 10), const sf::Vector2f &pos = sf::Vector2f(0, 0));
	void addMovement(sf::Vector2f & movement);
	void resetMovements();
	void addSpiral(int count, int radius, int growthFactor);
	void moveOnce();

private:
	vector<sf::Vector2f> movements;
};