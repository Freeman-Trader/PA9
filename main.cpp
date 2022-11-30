
#include <SFML/Graphics.hpp>

#define WINDOWS_WIDTH 500
#define WINDOWS_HEIGHT 500

#define MOVEMENT_SPEED .2f

int main()
{
	unsigned int direction = 0;

	//Window
	sf::VideoMode defaultVM(WINDOWS_WIDTH, WINDOWS_HEIGHT);
	sf::RenderWindow Window(defaultVM, "Pac-Man", sf::Style::Default);


	//Title - Currently needs a font .ttf file to work with
	/*sf::Font defaultFont;
	if(!defaultFont.loadFromFile("arial.ttf"))
		{return -1;}
	sf::Text titleName("PACMAN", defaultFont, 50);*/


	//Pacman Object
	sf::CircleShape shape;
	shape.setRadius(50.f);
	shape.setOutlineThickness(5.f);
	shape.setFillColor(sf::Color::Yellow);
	shape.setOutlineColor(sf::Color::Red);



	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			direction = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			direction = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			direction = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			direction = 4;
		}

		switch (direction)
		{
		case 1: shape.move(0.f, -MOVEMENT_SPEED);
			break;
		case 2: shape.move(MOVEMENT_SPEED, 0.f);
			break;
		case 3: shape.move(0.f, MOVEMENT_SPEED);
			break;
		case 4: shape.move(-MOVEMENT_SPEED, 0.f);
			break;
		default:
			break;
		}

		Window.clear();
		Window.draw(shape);
		//Window.draw(titleName);
		Window.display();
	}

	return 0;
}
