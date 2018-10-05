#include "stdafx.h"
#include "World.h"

#include "EntityNotFoundException.h"
#include "Mobile.h"
#include "NotImplementedException.h"
#include "Human.h"

namespace Core
{
    void World::onTick(Float elapsed)
    {
        for (size_t i = 0; i < entities_.size(); ++i)
        {
            for (size_t j = i + 1; j < entities_.size(); ++j)
            {
                entities_[i]->collide(*entities_[j].get());
            }
        }

        for (auto&& entity : entities_)
        {
            entity->onTick(elapsed);
        }
    }

    void World::createEntity(const String& name)
    {
        if (name == "Human")
        {
            entities_.push_back(
                alloc<Human>(
                    Vector3(0., 0., 0.),
                    Vector3::one(),
                    Vector3::zero()
                )
            );
        }
        else
        {
            throw EntityNotFoundException();
        }
    }

    void World::destroyEntity(const Ptr<Entity>& entity)
    {
        throw NotImplementedException();
    }
}
