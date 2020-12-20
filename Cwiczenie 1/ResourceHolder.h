#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>


namespace Resources
{
	enum TextureID 
	{ 
		Landscape, 
		Airplane, 
		AirplaneLeft, 
		AirplaneRight,
		Missle, 
		Eagle, 
		Raptor
	};

	//typedef ResourceHolder<sf::Texture, Resources::ID> TextureHolder;
}

template <typename Resource, typename ResourceID>
class ResourceHolder
{
	public:

		void				load(ResourceID resourceID, std::string fileName);

		template<typename Parmeters>
		void				load(ResourceID resourceID, std::string fileName, const Parmeters& secondParam);

		Resource&			get(ResourceID);
		const Resource&		get(ResourceID) const;

	private:
		
		std::map<ResourceID, std::unique_ptr<Resource>> mResourceMap;


};

typedef ResourceHolder<sf::Texture, Resources::TextureID> TextureHolder;

#include "ResourceHolder.inl"