#include "Game.h"
#include <cassert>
#include "ResourceHolder.h"
#include "Enity.hpp"

using namespace Resources;

Game::Game()
	: mWindow(sf::VideoMode(800, 600), "SFML Application",sf::Style::Close)
	, mWorld(mWindow)
{

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
	mWorld.update(deltaTime);
}

void Game::render()
{
	mWorld.draw();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}

void Game::handlerPlayerInput(sf::Keyboard::Key key,bool isPressed)
{
	/*if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		isMovingUp = isPressed;
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		isMovinDown = isPressed;
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		isMovingLeft = isPressed;
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		isMovingRight = isPressed;*/
}
