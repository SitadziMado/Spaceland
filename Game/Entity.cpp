#include "stdafx.h"
#include "Entity.h"

#include "IMotionModel.h"

namespace Core
{
    Entity::Entity(
        const String& name, 
        const Ptr<IMotionModel>& motionModel,
        const Ptr<ICollisionModel>& collisionModel
    ) : name_(name), motionModel_(motionModel), collisionModel_(collisionModel)
    {}

    void Entity::collide(const Entity& rhs)
    {
        collisionModel_->collide(
            *rhs.collisionModel_.get(),
            *motionModel_.get(),
            *rhs.motionModel_.get()
        );
    }

    const Vector3& Entity::getPosition() const
    {
        return motionModel_->getPosition();
    }

    void Entity::setPosition(const Vector3& value)
    {
        motionModel_->setPosition(value);
    }
}
