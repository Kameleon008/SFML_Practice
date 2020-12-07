#include "NamespaceTexture.h"


namespace Textures
{
	TextureHolder::TextureHolder()
	{

	}
	
	void TextureHolder::load(Textures::ID id, const std::string& fileName)
	{
		std::unique_ptr<sf::Texture> texture(new sf::Texture());
		texture->sf::Texture::loadFromFile(fileName);

		mTextureMap.insert(std::make_pair(id, std::move(texture)));
	}


	sf::Texture& TextureHolder::get(Textures::ID id)
	{
		auto found = mTextureMap.find(id);
		return *found->second;
	}

	const sf::Texture& TextureHolder::get(Textures::ID id) const
	{
		auto found = mTextureMap.find(id);
		return *found->second;
	}
}
