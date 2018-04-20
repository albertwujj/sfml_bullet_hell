#pragma once

#include "header.h"


class Homing : public Bullet
{
public:
	Homing(const sf::Texture &texture, const sf::IntRect &rectangle, sf::Vector2f &pos = sf::Vector2f(0, 0)) :
		Bullet(texture, rectangle, pos)
	{
	}
	void moveOnce(float speed);
	void setTarget(Vector2f target);
private:
	Vector2f target = Vector2f(0,0);
};