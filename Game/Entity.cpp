#include "stdafx.h"
#include "Entity.h"

namespace Core
{
    Entity::Entity(const String& name, const Ptr<IMotionModel>& motionModel)
        : name_(name), motionModel_(motionModel)
    {}

    const Vector3& Entity::getPosition() const
    {
        return position_;
    }

    void Entity::setPosition(const Vector3& value)
    {
        position_ = value;
    }
}
