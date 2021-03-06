#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.h"

class SpriteNode : public SceneNode
{
	public:
							SpriteNode(const sf::Texture& texture);
							SpriteNode(const sf::Texture& texture, sf::IntRect& rect);

	private:
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;

	private:
		sf::Sprite			mSprite;
};

