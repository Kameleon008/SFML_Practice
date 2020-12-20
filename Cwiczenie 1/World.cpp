#include "World.h"
#include "SpriteNode.h"
#include "Aircraft.h"
#include <iostream>

World::World(sf::RenderWindow& window) :
	mWindow(window),
	mTextureHolder(),
	mWorldView(window.getDefaultView()),
	mSceneGraph(),
	mSceneLayers(),
	mWorldBounds(0,0,window.getSize().x, 2000.f),
	mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f),
	mScrollSpeed(-50.f)
{
	loadTextures();
	buildScene();
	mWorldView.setCenter(mSpawnPosition);
}


void World::update(sf::Time dt)
{
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	if (position.x <= mWorldBounds.left + 150.f
		|| position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	{
		velocity.x = -velocity.x;
		mPlayerAircraft->setVelocity(velocity);
	}

	mSceneGraph.update(dt);

}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);

}

void World::loadTextures()
{
	std::cout << "Rozpoczeto ladowanie zasobow gry" << std::endl;
	mTextureHolder.load(Resources::TextureID::Eagle, "Media/Textures/eagle.png");
	mTextureHolder.load(Resources::TextureID::Raptor, "Media/Textures/raptor.png");
	mTextureHolder.load(Resources::TextureID::Landscape, "Media/Textures/Background.png");
	std::cout << "Zakonczono ladowanie zasobow gry" << std::endl;
}

void World::buildScene()
{
	
	for (int i = 0; i < LayerCount; i++)
	{
		SceneNode::Ptr layer(new(SceneNode));
		mSceneLayers[i] = layer.get();
		mSceneGraph.attachChild(std::move(layer));

	}

	sf::Texture& backgroundTexture = mTextureHolder.get(Resources::Landscape);
	sf::IntRect backgroundBoundsRect(mWorldBounds);
	backgroundTexture.setRepeated(true);
	//backgroundTexture.setSmooth(true);

	std::unique_ptr<SpriteNode> backgroundSprite( new SpriteNode(backgroundTexture,backgroundBoundsRect));
	backgroundSprite->setPosition(mWorldBounds.left,mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextureHolder));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(80.f, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));

	std::unique_ptr<Aircraft> leftGuard(new Aircraft(Aircraft::Raptor, mTextureHolder));
	leftGuard->setPosition(-50.f, 80.f);
	leftGuard->setVelocity(0, 0);
	mPlayerAircraft->attachChild(std::move(leftGuard));

	std::unique_ptr<Aircraft> rightGuard(new Aircraft(Aircraft::Raptor, mTextureHolder));
	rightGuard->setPosition(50.f, 80.f);
	rightGuard->setVelocity(0, 0);
	mPlayerAircraft->attachChild(std::move(rightGuard));

}