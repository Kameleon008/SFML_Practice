#include "Enity.hpp"
#include <assert.h>

void Enity::setVelocity(sf::Vector2f velocityVector)
{
	mVelocity = velocityVector;
}

void Enity::setVelocity(float x, float y)
{
	mVelocity.x = x;
	mVelocity.y = y;
}

sf::Vector2f  Enity::getVelocity() const
{
	return mVelocity;
}

