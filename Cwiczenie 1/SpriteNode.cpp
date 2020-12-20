#include "SpriteNode.h"

SpriteNode::SpriteNode(const sf::Texture& texture):
	mSprite(texture)
{

}

SpriteNode::SpriteNode(const sf::Texture& texture, sf::IntRect& rect) :
	mSprite(texture,rect)
{

}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(mSprite, state);
}