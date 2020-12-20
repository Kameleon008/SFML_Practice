#include "SceneNode.h"
#include <assert.h>

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
	drawCurrent(target, state);
	for (auto i = mChildren.begin(); i != mChildren.end(); ++i)
	{
		(*i)->draw(target, state);
	}
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
{

}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{

}

void SceneNode::updateChildren(sf::Time dt)
{
	for (auto i = mChildren.begin(); i != mChildren.end(); ++i)
	{
		(*i)->update(dt);
	}
}

sf::Transform SceneNode::getWorldTranform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (auto node = this; node != nullptr; node->mParent)
	{
		transform = node->getTransform() * transform;
	}
	return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTranform() * sf::Vector2f();
}