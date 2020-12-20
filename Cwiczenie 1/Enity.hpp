#pragma once
#include <SFML/Graphics.hpp>

class Enity
{
public:

	void				setVelocity(sf::Vector2f velocityVector);
	void				setVelocity(float velocityInDirectionX, float velocityInDirectionY);
	sf::Vector2f		getVelocity() const;


private:
	sf::Vector2f		mVelocity;

};
