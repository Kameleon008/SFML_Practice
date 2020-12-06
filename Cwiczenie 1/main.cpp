#include <SFML/Graphics.hpp>

int main()
{
	int width = 800;
	int height = 600;
	
	float circleCenterY = (float)width / 2.f;
	float circleCenterX = (float)height / 2.f;
	

	sf::RenderWindow window(sf::VideoMode(width, height), "Title");
	
	sf::Event event;

	sf::CircleShape shape;
	shape.setRadius(40);
	shape.setPosition(circleCenterX,circleCenterY);
	shape.setFillColor(sf::Color::Magenta);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			window.clear();
			window.draw(shape);
			window.display();
		}
	}

	return 0;
}