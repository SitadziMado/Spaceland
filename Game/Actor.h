#pragma once

#include "Mobile.h"

namespace Core
{
    class Actor : public Mobile
    {
    public:
        Actor(
            const String& name, 
            Float mass, 
            Float width,
            Float height,
            const Vector3& position,
            const Vector3& velocity, 
            const Vector3& acceleration
        );
    };
}
