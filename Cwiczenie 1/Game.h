#pragma once
#include <SFML/Graphics.hpp>
#include "NamespaceTexture.h"
class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time);
	void render();
	void handlerPlayerInput(sf::Keyboard::Key,bool);
	void updateShipView();

private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	Textures::TextureHolder textureHolder;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	bool isMovingUp;
	bool isMovinDown;
	bool isMovingLeft;
	bool isMovingRight;
	

};
