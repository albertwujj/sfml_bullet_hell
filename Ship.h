#pragma once
#include <SFML/Graphics.hpp>


class Ship : public sf::CircleShape {
	Ship();
	Ship(sf::Vector2f &pos, const sf::Color &c, float r) : CircleShape(r);
	
};



