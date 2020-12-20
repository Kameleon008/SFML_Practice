#pragma once

#include "ResourceHolder.h"
#include <string>

template <typename Resource, typename ResourceID>
void ResourceHolder<Resource,ResourceID>::load(ResourceID resourceID, std::string fileName)
{
	try
	{
		std::unique_ptr<Resource> resource(new Resource());
		resource->loadFromFile(fileName);
		mResourceMap.insert(std::make_pair(resourceID, std::move(resource)));

	}
	catch (std::runtime_error& er)
	{
		printf(er.what());
	}
	
}

template <typename Resource,typename ResourceID>
template <typename Parameters>
void ResourceHolder<Resource, ResourceID>::load(ResourceID resourceID, std::string fileName,const Parameters& secondParam)
{
	try
	{
		std::unique_ptr<Resource> resource(new Resource());
		resource->loadFromFile(fileName, secondParam);
		mResourceMap.insert(std::make_pair(resourceID, std::move(resource)));
	}
	catch (std::runtime_error& er)
	{
		printf(er.what());
	}
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
