#pragma once

#include "ResourceHolder.h"

template <typename Resource, typename ResourceID>
void ResourceHolder<Resource,ResourceID>::load(ResourceID resourceID, std::string fileName)
{
	std::unique_ptr<Resource> resource(new Resource());
	resource->loadFromFile(fileName);
	mResourceMap.insert(std::make_pair(resourceID, std::move(resource)));
}


template <typename Resource, typename ResourceID>
Resource& ResourceHolder<Resource, ResourceID>::get(ResourceID resourceID)
{
	auto foundResource = mResourceMap.find(resourceID);
	return *foundResource->second;
}

template <typename Resource, typename ResourceID>
const Resource& ResourceHolder<Resource, ResourceID>::get(ResourceID resourceID) const
{
	auto foundResource = mResourceMap.find(resourceID);
	return *foundResource->second;
}
