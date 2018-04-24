
#include <iostream>
#include <math.h>
#include "Player.h"
namespace C
{

	const float Window_Width = 1080;
	const float Window_Height = 720;

}

Player::Player()
	: cBall_Rad(50.0f), mPos(C::Window_Width / 2, C::Window_Height / 2), mSpeed(0, 0), mAcceleration(3500.0f), mMax_speed(800.0f),
	mUp(0), mDown(0), mLeft(0), mRight(0)
{
	texture.loadFromFile("player.png");
	mShip.setTexture(texture);
	mShip.setPosition(mPos);
	mShip.scale(0.5, 0.5);
	mShip.setTextureRect(sf::IntRect(100, 100, 100, 100));
}


sf::Sprite Player::getSprite() {
	return mShip;
}
void Player::Render(sf::RenderWindow &window)
{


	window.draw(mShip);
}

void Player::Update(sf::Time delta)
{
	Handle_Input();
	Set_Vel();

	mPos += Calc_Speed(delta) * delta.asSeconds();

	mShip.setPosition(mPos);
}


///////////////////
//private functions

void Player::Handle_Input()
{
	//set position equal to keypresses
	mUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	mDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	mLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	mRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	if (mPos.x < 0)
	{
		mPos.x = 0;
		mSpeed.x = 0;

	}
	if (mPos.x >= C::Window_Width - 50)
	{
		mPos.x = C::Window_Width - 50;
		mSpeed.x = 0;

	}
	if (mPos.y < 0)
	{
		mPos.y = 0;
		mSpeed.y = 0;

	}
	if (mPos.y >= C::Window_Height - 50)
	{
		mPos.y = C::Window_Height - 50;
		mSpeed.y = 0;

	}



	if (mUp && mDown) { //if trying to press both dont do anything on y-axis
		mUp = false;
		mDown = false;
	}

	if (mLeft && mRight) { //if trying to press both dont do anything on x-axis
		mLeft = false;
		mRight = false;
	}
}

sf::Vector2f Player::getPosition() {
	return mPos;
}

bool Player::Set_Vel()
{
	if (!mSpeed.y && (!mUp || !mDown)) {
		mVel.y = 0;
	}
	if (!mSpeed.x) {
		mVel.x = 0;
	}

	if (mUp) {
		mVel.y = -1;
	}
	else if (mDown) {
		mVel.y = 1;
	}
	if (mLeft) {
		mVel.x = -1;
	}
	else if (mRight) {
		mVel.x = 1;
	}

	return mVel.y || mVel.x;
}

sf::Vector2f Player::Calc_Speed(sf::Time delta)
{
	//accelerate
	////////////

	//Y-Axis
	if (mSpeed.y < mMax_speed && mSpeed.y > -mMax_speed && (mUp || mDown)) {
		mSpeed.y += mAcceleration * mVel.y * delta.asSeconds();
	}

	if (mSpeed.y > mMax_speed || mSpeed.y < -mMax_speed)
		mSpeed.y = mMax_speed * mVel.y;

	//X-Axis
	if (mSpeed.x < mMax_speed && mSpeed.x > -mMax_speed && (mLeft || mRight)) {
		mSpeed.x += mAcceleration * mVel.x * delta.asSeconds();
	}

	if (mSpeed.x > mMax_speed || mSpeed.x < -mMax_speed)
		mSpeed.x = mMax_speed * mVel.x;

	//decelerate
	////////////

	//Y-Axis
	if (!mUp && !mDown) {
		if (mVel.y > 0) {
			mSpeed.y -= mAcceleration * delta.asSeconds();
			if (mSpeed.y <= 0) {
				mSpeed.y = mVel.y = 0.0f;
			}
		}
		else if (mVel.y < 0) {
			mSpeed.y += mAcceleration * delta.asSeconds();
			if (mSpeed.y >= 0) {
				mSpeed.y = mVel.y = 0.0f;
			}
		}
	}

	//X-Axis
	if (!mLeft && !mRight) {
		if (mVel.x > 0) {
			mSpeed.x -= mAcceleration * delta.asSeconds();
			if (mSpeed.x <= 0) {
				mSpeed.x = mVel.x = 0.0f;
			}
		}
		else if (mVel.x < 0) {
			mSpeed.x += mAcceleration * delta.asSeconds();
			if (mSpeed.x >= 0) {
				mSpeed.x = mVel.x = 0.0f;
			}
		}
	}

	return mSpeed;
}