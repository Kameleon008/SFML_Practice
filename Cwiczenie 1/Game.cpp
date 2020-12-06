#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, mPlayer()
	
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
	isMovingUp = false;
	isMovinDown = false;
	isMovingLeft = false;
	isMovingRight = false;
}

void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlerPlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlerPlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{
	const float movmentSpeed = 0.3;
	sf::Vector2f movment(0.f,0.f);
	if (isMovingUp == true)
		movment.y -= movmentSpeed;
	if (isMovinDown == true)
		movment.y += movmentSpeed;
	if (isMovingLeft == true)
		movment.x -= movmentSpeed;
	if (isMovingRight == true)
		movment.x += movmentSpeed;

	mPlayer.move(movment);
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handlerPlayerInput(sf::Keyboard::Key key,bool isPressed)
{
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		isMovingUp = isPressed;
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		isMovinDown = isPressed;
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		isMovingLeft = isPressed;
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		isMovingRight = isPressed;
}