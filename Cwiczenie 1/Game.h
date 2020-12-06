#include <SFML/Graphics.hpp>

#pragma once
class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();
	void handlerPlayerInput(sf::Keyboard::Key,bool);

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	bool isMovingUp;
	bool isMovinDown;
	bool isMovingLeft;
	bool isMovingRight;

};
