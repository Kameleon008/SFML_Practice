#include "Game.h"
#include <cassert>
#include "ResourceHolder.h"
#include "Enity.hpp"

using namespace Resources;

Game::Game()
	: mWindow(sf::VideoMode(800, 600), "SFML Application")
	, mPlayer()
	, mBakground()
	, textureHolder()
	
{

	//assert(false);
	printf("Rozpoczeto ladowanie gry\n");
	textureHolder.load(Airplane ,"Media/Textures/eagle.png");
	textureHolder.load(AirplaneLeft, "Media/Textures/eagle_left.png");
	textureHolder.load(AirplaneRight, "Media/Textures/eagle_right.png");
	textureHolder.load(Landscape, "Media/Textures/Background.png");
	textureHolder.load(Eagle, "Media/Textures/eagle.png");
	textureHolder.load(Raptor, "Media/Textures/raptor.png");
	//mTexture.setSmooth(true);
	mPlayer.setTexture(textureHolder.get(Raptor));
	mPlayer.setScale(1, 1);
	mPlayer.setPosition(100.f, 100.f);
	mBakground.setTexture(textureHolder.get(Landscape));
	mBakground.setScale(600.f/900.f, 600.f/900.f);
	isMovingUp = false;
	isMovinDown = false;
	isMovingLeft = false;
	isMovingRight = false;
	printf("Zaladowano komponenty gry");
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
		{	timeSiceLastUpdate -= timePerFrame;
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
	//updateShipView();
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mBakground);
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

void Game::updateShipView()
{
	if (isMovingLeft && !isMovingRight)
		mPlayer.setTexture(textureHolder.get(AirplaneLeft));
	else if (!isMovingLeft && isMovingRight)
		mPlayer.setTexture(textureHolder.get(AirplaneRight));

}