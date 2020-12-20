#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "Enity.hpp"

class Aircraft : public Enity
{
public:
	enum Type
	{
		Raptor,
		Eagle,
	};

public:
	Aircraft(Aircraft::Type type, const TextureHolder& texture);
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;


private:

	Type					mType;
	sf::Sprite				mSptite;
	Resources::TextureID	toTextureID(Aircraft::Type type);
};