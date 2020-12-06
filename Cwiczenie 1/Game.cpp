#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(800, 600), "SFML Application")
	, mPlayer()
	, mTexture()
{
	if (!mTexture.loadFromFile("Media/Textures/Eagle.png"))
	{

	}
	mTexture.setSmooth(true);
	mPlayer.setTexture(mTexture);
	mPlayer.setScale(0.4, 0.4);
	mPlayer.setPosition(100.f, 100.f);
	isMovingUp = false;
	isMovinDown = false;
	isMovingLeft = false;
	isMovingRight = false;
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSiceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSiceLastUpdate += clock.restart();
		if (timeSiceLastUpdate >= timePerFrame)
		{	
			timeSiceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
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

void Game::update(sf::Time deltaTime)
{
	const float movmentSpeed = 400;
	sf::Vector2f movment(0.f,0.f);
	float x = deltaTime.asSeconds();

	if (isMovingUp == true)
		movment.y -= movmentSpeed;
	if (isMovinDown == true)
		movment.y += movmentSpeed;
	if (isMovingLeft == true)
		movment.x -= movmentSpeed;
	if (isMovingRight == true)
		movment.x += movmentSpeed;

	
	mPlayer.move(movment*x);
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