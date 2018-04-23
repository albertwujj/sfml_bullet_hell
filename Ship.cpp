#include "Ship.h"

Ship::Ship() {

}

Ship::Ship(sf::Vector2f &pos, const sf::Color &c, float r) {
	this->setPosition(pos);
	this->setFillColor(c);
}

