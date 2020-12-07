#pragma once
#include <SFML/Graphics.hpp>

namespace Textures
{
	enum ID { Landscape, Airplane, AirplaneLeft, AirplaneRight, Missle};

	class TextureHolder
	{
		public:
			TextureHolder();
			void load(Textures::ID id, const std::string& fileName);
			sf::Texture& get(Textures::ID id);
			const sf::Texture& get(Textures::ID id) const;

		private:

			std::map<Textures::ID,
				std::unique_ptr<sf::Texture>> mTextureMap;
	};
}