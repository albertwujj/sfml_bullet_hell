#include "header.h"
#include "Collision.h"
#include "Bullet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
	sf::CircleShape shape(30.f);
	sf::Sprite sprite;
	shape.setFillColor(sf::Color::Green);
	Bullet bullet1(sf::Texture(), sf::IntRect(2,2,2,2));
	Bullet bullet2(sf::Texture(), sf::IntRect(3, 3, 2, 2));

	
	float delta_x = 0.0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A)
					shape.move(-3,0);
				else if (event.key.code == sf::Keyboard::D) {
					shape.move(3,0);
				}
				cout << Collision::CircleTest(bullet1, bullet2);
			}
		}
		window.clear();
		window.draw(shape);
		window.draw(bullet1);
		window.draw(bullet2);
		window.display();
	}

	return 0;
}