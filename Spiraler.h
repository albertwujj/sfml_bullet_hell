#pragma once

//class for shooting many spiral PatternBullets
#include <list>
using std::list;

class Spiraler
{
public:
	Spiraler(list<PatternBullet> bullets);
	void updateAndRender(sf::Time delta, sf::RenderWindow & window);

private:
	list<PatternBullet> bullets;
	list<PatternBullet> activeBullets;
	//delay between firing each bullet in milliseconds
	int delay;
	int sinceLast;
	bool cclockwise;
};