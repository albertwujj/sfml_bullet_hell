#pragma once

#include "header.h"

class Bullet : public sf::Sprite
{
public:
	Bullet(const sf::Texture &texture, const sf::IntRect &rectangle, sf::Vector2f &pos = sf::Vector2f(0, 0)):
		Sprite(texture, rectangle)
	{
		this->setPosition(pos);
	}
	vector<int> movement;

private:
	
};