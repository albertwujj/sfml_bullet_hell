#include "header.h"

class Vector2d : public Vector2f {
public:
	Vector2d(int x, int y) : Vector2f(x, y) {
	}
	int getLength() {
		return sqrt(this->x * this->x + this->y * this->y);
	}
};