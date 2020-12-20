#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "ResourceHolder.h"
#include "SceneNode.h"
#include "Aircraft.h"

class World : private sf::NonCopyable
{
	public:
							World(sf::RenderWindow& renderWindow);
		void				update(sf::Time dt);
		void				draw();

	private:
		void				loadTextures();
		void				buildScene();

	private:

		enum Layer
		{
			Background,
			Air,
			LayerCount
		};

	private:
		sf::RenderWindow&							mWindow;
		sf::View									mWorldView;
		TextureHolder								mTextureHolder;
		SceneNode									mSceneGraph;
		std::array <SceneNode*,LayerCount>			mSceneLayers;

		sf::IntRect									mWorldBounds;
		sf::Vector2f								mStartPosition;
		Aircraft*									mPlayerAircraft;

		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;


};

