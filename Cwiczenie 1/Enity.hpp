#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

#pragma region class Enity
class Enity
{
public:

	void				setVelocity(sf::Vector2f velocityVector);
	void				setVelocity(float velocityInDirectionX, float velocityInDirectionY);
	sf::Vector2f		getVelocity() const;


private:
	sf::Vector2f		mVelocity;

};
#pragma endregion

#pragma region class SceneNode
class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode>		Ptr;

public:
	SceneNode();
	void									attachChild(Ptr);
	Ptr										detachChild(const SceneNode&);

private:
	virtual void							draw(sf::RenderTarget& target, sf::RenderStates state) const;
	virtual void							drawCurrnet(sf::RenderTarget& target, sf::RenderStates state) const;

private:
	std::vector<Ptr>						mChildren;
	SceneNode* mParent;


};
#pragma endregion

#pragma region class Aircraft
class Aircraft: public Enity
{
public:
	enum Type
	{
		Raptor,
		Eagle,
	};

public:
	explicit				Aircraft(Type type, const TextureHolder& texture);
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;


private:

	Type					mType;
	sf::Sprite				mSptite;
	Resources::TextureID	toTextureID(Aircraft::Type type);
};
#pragma endregion
