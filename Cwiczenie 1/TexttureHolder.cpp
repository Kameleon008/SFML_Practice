#include "TexttureHolder.h"


TextureHolder::TextureHolder()
{

}

void TextureHolder::load(Textures::TextureID id, const std::string& fileName)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	texture->sf::Texture::loadFromFile(fileName);

	mTextureMap.insert(std::make_pair(id, std::move(texture)));
}


sf::Texture& TextureHolder::get(Textures::TextureID id)
{
	auto found = mTextureMap.find(id);
	return *found->second;
}

const sf::Texture& TextureHolder::get(Textures::TextureID id) const
{
	auto found = mTextureMap.find(id);
	return *found->second;
}

