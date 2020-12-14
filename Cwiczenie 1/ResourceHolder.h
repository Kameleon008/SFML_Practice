#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>


namespace Resources
{
	enum ID { Landscape, Airplane, AirplaneLeft, AirplaneRight, Missle };
}


template <typename Resource, typename ResourceID>
class ResourceHolder
{
	public:

		void				load(ResourceID resourceID, std::string fileName);
		Resource&			get(ResourceID);
		const Resource&		get(ResourceID) const;

	private:
		
		std::map<ResourceID, std::unique_ptr<Resource>> mResourceMap;


};

#include "ResourceHolder.inl"