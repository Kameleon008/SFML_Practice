#include "Aircraft.h"
#include "Enity.hpp"

Aircraft::Aircraft(Type type, const TextureHolder& texture) :
	mType(type),
	mSptite(texture.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSptite.getLocalBounds();
	mSptite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(mSptite, state);
}

Resources::TextureID Aircraft::toTextureID(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Raptor:
		return Resources::TextureID::Raptor;
	case Aircraft::Eagle:
		return Resources::TextureID::Eagle;
	default:
		break;
	}
	return Resources::TextureID::Eagle;
}