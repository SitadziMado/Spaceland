#include "stdafx.h"
#include "Entity.h"

namespace Core
{
    Entity::Entity(const String& name, const Vector3& position)
        : name_(name), position_(position)
    {}
}
