#pragma once
#include <SFML/Graphics.hpp>

namespace Textures
{
	enum TextureID { Landscape, Airplane, AirplaneLeft, AirplaneRight, Missle };
}

class TextureHolder
{
public:
	TextureHolder();
	void load(Textures::TextureID id, const std::string& fileName);
	sf::Texture& get(Textures::TextureID id);
	const sf::Texture& get(Textures::TextureID id) const;

private:

	std::map < Textures::TextureID, std::unique_ptr < sf::Texture>> mTextureMap;
};
	
