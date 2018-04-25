

#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player
{
public:
	friend class Homing;
	Player();

	void Render(sf::RenderWindow &window);
	void Update(sf::Time delta);
	sf::Vector2f getPosition();
	sf::Vector2f getVel();
	sf::Sprite getSprite();
	
private:
	void Handle_Input();
	bool Set_Vel();
	sf::Vector2f Calc_Speed(sf::Time delta);
	sf::Texture texture;
	sf::Sprite mShip;
	sf::Vector2f mVel;
	sf::Vector2f mPos;
	//variables for clean movement
	sf::Vector2f mSpeed;
	float mAcceleration;
	const float mMax_speed;

	//variables for input
	bool mUp;
	bool mDown;
	bool mLeft;
	bool mRight;

	const float cBall_Rad;
};


#endif //PLAYER_HPP

