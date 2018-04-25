#pragma once



float getLength(sf::Vector2f vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f normalize(sf::Vector2f vec) {
	return vec / getLength(vec);
}

sf::Vector2f setLength(sf::Vector2f vec, float length) {
	return length * normalize(vec);
}

