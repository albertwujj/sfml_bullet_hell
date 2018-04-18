#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	

	sf::RenderWindow window(sf::VideoMode(2000, 1500), "SFML works!");
	sf::CircleShape shape(20.f);
	sf::RectangleShape rectangle(sf::Vector2f(10,20));
	rectangle.setPosition(sf::Vector2f(1000, 50));
	rectangle.setSize(sf::Vector2f(40, 100));
	rectangle.setFillColor(sf::Color::Yellow);
	shape.setFillColor(sf::Color::Green);
	
	while (window.isOpen())
	{
		rectangle.move(0, 0.5);
		rectangle.getPosition().y;
		//cout << "Position: " << rectangle.getPosition().y << endl;
		/*if (rectangle.getPosition().y > 1600) {
			rectangle.setPosition(1000, 50);
		}*/
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				shape.move(10, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				shape.move(-10, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				shape.move(0, -10);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				shape.move(0, 10);
			}
		}

		window.clear();
		window.draw(shape);
		window.draw(rectangle);
		window.display();
	}

	return 0;
}