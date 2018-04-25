#pragma once
#include <vector>
#include "Bullet.h"

using std::vector;

class PatternBullet : public Bullet
{
public:
	PatternBullet(const sf::Vector2f &pos = sf::Vector2f(0, 0), const sf::Texture &texture = sf::Texture(), const sf::IntRect &rectangle = sf::IntRect(10, 10, 10, 10));
	void addMovement(sf::Vector2f & movement);
	void resetMovements();
	void PatternBullet::addSpiral(int initialDir = 0, bool counterclockwise = false, int finalRadius = 1000, int initRadius = 10);
	void update(sf::Time & delta);

private:
	vector<sf::Vector2f> movements;
	int sinceLast;
	int delay;
};