#pragma once
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode>		Ptr;

public:
											SceneNode();
	void									attachChild(Ptr);
	Ptr										detachChild(const SceneNode&);
	void									update(sf::Time dt);
	sf::Transform							getWorldTranform() const;
	sf::Vector2f							getWorldPosition() const;


private:
	virtual void							draw(sf::RenderTarget& target, sf::RenderStates state) const;
	virtual void							drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;
	virtual void							updateCurrent(sf::Time dt);
	virtual void							updateChildren(sf::Time dt);


private:
	std::vector<Ptr>						mChildren;
	SceneNode* mParent;


};