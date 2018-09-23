#pragma once

#include "Entity.h"
#include "ForceManager.h"
#include "Force.h"
#include "Vector3.h"

namespace Core
{
    class Mobile : public Entity
    {
    public:
        Mobile(
            const String& name,
            Float mass,
            const Vector3& position,
            const Vector3& velocity = Vector3::zero(),
            const Vector3& acceleration = Vector3::zero()
        );
    };
}
