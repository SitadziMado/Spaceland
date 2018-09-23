#include "stdafx.h"
#include "World.h"

#include "NotImplementedException.h"
#include "Mobile.h"

namespace Core
{
    void World::onTick(Float elapsed)
    {
        for (auto&& entity : entities_)
        {
            entity->onTick(elapsed);
        }
    }

    void World::createEntity(const String& name)
    {
        throw NotImplementedException();
    }

    void World::destroyEntity(const Ptr<Entity>& entity)
    {
        throw NotImplementedException();
    }
}
