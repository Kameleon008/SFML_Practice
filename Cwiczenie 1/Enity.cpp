#include "Enity.hpp"
#include <assert.h>


#pragma region class Enity

/// <summary>
/// class Enity
/// 
/// </summary>

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
#pragma endregion

#pragma region class SceneNode

/// <summary>
/// SceneNode class
/// </summary>

SceneNode::SceneNode()
{

}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(),
		[&](Ptr& p) -> bool {return p.get() == &node; });

	//find_if zwaraca iterator do ostatniego elementu (w tym przypadku mChildren.end() je¿eli nie
	//wywo³ywaa funkcja (w tym przypadku wyra¿enie lamda) zwróci false dla ka¿dego elementu
	//st¹d sprawdzenie czy wyst¹pi³o takie zda¿enie
	assert(found != mChildren.end());
	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates state) const
{

	state.transform *= getTransform();
	drawCurrnet(target, state);
	for (auto i = mChildren.begin(); i!=mChildren.end(); ++i)
	{
		(*i)->draw(target,state);
	}
}

void SceneNode::drawCurrnet(sf::RenderTarget& target, sf::RenderStates state) const
{

}

#pragma endregion

#pragma region class Aircraft

/// <summary>
/// class Aircraft
/// </summary>

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
#pragma endregion




