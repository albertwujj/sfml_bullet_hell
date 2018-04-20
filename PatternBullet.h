#include "header.h"

class PatternBullet : public Bullet
{
public:
	PatternBullet(const sf::Texture &texture, const sf::IntRect &rectangle, sf::Vector2f &pos = sf::Vector2f(0, 0)) :
		Bullet(texture, rectangle, pos)
	{
	}
	void addMovement(Vector2f movement);
	void resetMovements();
	void addSpiral(int count, int radius, int growthFactor);
	void moveOnce();

private:
	vector<Vector2f> movements;
};