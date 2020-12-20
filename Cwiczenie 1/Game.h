#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "World.h"

class Game
{
public:
						Game();
	void				run();
private:
	void				processEvents();
	void				update(sf::Time);
	void				render();
	void				handlerPlayerInput(sf::Keyboard::Key,bool);

private:
	sf::RenderWindow	mWindow;
	World				mWorld;

	const sf::Time		timePerFrame = sf::seconds(1.f / 60.f);
	
	

};
