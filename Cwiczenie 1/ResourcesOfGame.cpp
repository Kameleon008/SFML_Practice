#pragma once
#include "ResourcesOfGame.h"
#include <cassert>
#include <SFML/Graphics.hpp>
#include <map>


template <typename Resource, typename ResourceID>
void ResourceHolder<Resource, ResourceID>::load(ResourceID id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(filename)));
	assert(inserted.second);
}

template <typename Resource, typename ResourceID>
Resource& ResourceHolder<Resource, ResourceID>::get(ResourceID id)
{
	auto found = mResourceMap.find(id);
	assert(found != mTextureMap.end());
	return *found->second;
}
