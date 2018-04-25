#pragma once




class Homing : public Bullet
{
public:
	Homing(const sf::Vector2f &pos = sf::Vector2f(0, 0), const sf::Texture &texture = sf::Texture(), float speed = 400.0, const sf::IntRect &rectangle = sf::IntRect(10, 10, 32, 32));
	void update(sf::Time & delta);
	void setTarget(const sf::Vector2f &target);
	void setSpeed(int speed);
private:
	sf::Vector2f target;
	float speed;
};