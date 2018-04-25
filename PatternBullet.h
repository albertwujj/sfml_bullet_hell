#ifndef PATTERN_BULLET_H
#define PATTERN_BULLET_H


class PatternBullet : public Bullet
{
public:
	PatternBullet(const sf::Vector2f &pos = sf::Vector2f(0, 0), const sf::Texture &texture = sf::Texture(), const sf::IntRect &rectangle = sf::IntRect(10, 10, 20, 20));
	void addMovement(const sf::Vector2f & movement);
	void resetMovements();
	void PatternBullet::addSpiral(bool counterclockwise = 0, int finalRadius = 500, int initRadius = 10);
	void update(sf::Time & delta);

private:
	list<sf::Vector2f> movements;
	int sinceLast;
	int delay;
};

#endif