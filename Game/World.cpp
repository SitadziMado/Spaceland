#include "stdafx.h"
#include "World.h"

#include "NotImplementedException.h"
#include "Mobile.h"

namespace Core
{
    void World::onTick(Float elapsed)
    {
        for (size_t i = 0; i < entities_.size(); ++i)
        {
            for (size_t j = i + 1; j < entities_.size(); ++j)
            {
                entities_[i]->collide(entities_[j]);
            }
        }

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
