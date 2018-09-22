#include "stdafx.h"
#include "World.h"

#include "NotImplementedException.h"
#include "Mobile.h"

namespace Core
{
    void World::onTick(Float msElapsed)
    {
        for (auto&& entity : entities_)
        {
            entity->onTick(msElapsed);
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
