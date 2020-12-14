#pragma once
#include <SFML/Graphics.hpp>

template <typename Resource, typename ResourceID>
class ResourceHolder
{
	public:
		void					load(ResourceID resourceID, const std::string& fileName);
		Resource&				get(ResourceID resourceID);
		const Resource&			get(ResourceID resourceID) const;

	private:
		std::map<ResourceID,std::unique_ptr<Resource>>		mResourceMap;
};
