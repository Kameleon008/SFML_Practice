#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.h"

class Enity : public SceneNode
{
public:

	void				setVelocity(sf::Vector2f velocityVector);
	void				setVelocity(float velocityInDirectionX, float velocityInDirectionY);
	sf::Vector2f		getVelocity() const;
	virtual void		updateCurrent(sf::Time dt);

private:
	sf::Vector2f		mVelocity;


};
