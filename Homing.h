#pragma once
#include <vector>
#include "Bullet.h"


class Homing : public Bullet
{
public:
	Homing(float speed = 500.0, const sf::Vector2f &pos = sf::Vector2f(0, 0), const sf::Texture &texture = sf::Texture(), const sf::IntRect &rectangle = sf::IntRect(10, 10, 32, 32));
	void moveOnce(sf::Time delta);
	void setTarget(const sf::Vector2f &target);
	void Homing::setSpeed(int speed);
private:
	sf::Vector2f target;
	float speed;
};