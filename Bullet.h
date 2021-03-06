#ifndef BULLET_H
#define BULLET_H

class Bullet : public sf::Sprite
{
public:
	Bullet(const sf::Texture &texture, const sf::IntRect &rectangle = sf::IntRect(10,10,32,32), const sf::Vector2f pos = sf::Vector2f(0, 0)):
		Sprite(texture)
	{
		this->setPosition(pos);
	}
	virtual void update(sf::Time & delta) = 0;
private:
	int lifetime;

	
};

#endif