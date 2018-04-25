#include <SFML/Graphics.hpp>
#include "header.h"
#include "Bullet.h"
#include "PatternBullet.h"
#include "Spiraler.h"
#include <list>


using std::list;

Spiraler::Spiraler(list<PatternBullet> bullets) {
	this->bullets = bullets;
	delay = 300;
	sinceLast = 0;
	cclockwise = false;
}

void Spiraler::updateAndRender(sf::Time delta, sf::RenderWindow & window) {
	sinceLast += delta.asMilliseconds();
	if (sinceLast > delay) {
		PatternBullet bullet = bullets.front();
		bullets.pop_front();
		bullet.addSpiral(cclockwise);
		activeBullets.push_back(bullet);
		for (PatternBullet & bullet : activeBullets) {
			bullet.update(delta);
			const PatternBullet & cBullet = bullet;
			window.draw(cBullet);
		}
		cclockwise = !cclockwise;
		sinceLast = 0;
	}
}