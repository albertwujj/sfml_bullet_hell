#pragma once
#include <vector>
#include "Bullet.h"


class Homing : public Bullet
{
public:
	Homing(const sf::Texture &texture = sf::Texture(), const sf::IntRect &rectangle = sf::IntRect(10, 10, 32, 32), const sf::Vector2f &pos = sf::Vector2f(0, 0));
	void moveOnce(float speed);
	void setTarget(const sf::Vector2f &target);
private:
	sf::Vector2f target;
};