#include <SFML/Graphics.hpp>

#pragma once
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
	sf::Texture mTexture;
	sf::Texture mTextureLeft;
	sf::Texture mTextureRight;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	bool isMovingUp;
	bool isMovinDown;
	bool isMovingLeft;
	bool isMovingRight;
	

};
