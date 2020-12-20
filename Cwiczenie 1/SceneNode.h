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

private:
	virtual void							draw(sf::RenderTarget& target, sf::RenderStates state) const;
	virtual void							drawCurrnet(sf::RenderTarget& target, sf::RenderStates state) const;

private:
	std::vector<Ptr>						mChildren;
	SceneNode* mParent;


};