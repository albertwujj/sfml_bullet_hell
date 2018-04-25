#ifndef BULLET_GROUPS_H

#define BULLET_GROUPS_H

template <class T>
vector<T> createGroup(sf::Texture text, int count, sf::Vector2f corner, int spread);

//create a group of bullets whose positions are initialized within a 
//square whose corner and size are determined by corner and spread parameters
//respectively
template <class T>
vector<T> createGroup(sf::Texture text, int count, sf::Vector2f corner, int spread) {
	vector<T> *bullets = new vector<T>;
	int i = 0;
	for (i = 0; i < count; i++) {
		Vector2f pos = Vector2f(getRand() % spread + corner.x, getRand() % spread + corner.y);
		bullets->push_back(T(corner, text));
	}
	return *bullets;
}

#endif