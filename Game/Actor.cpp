#include "stdafx.h"
#include "Actor.h"

namespace Core
{
    Actor::Actor(
        const String& name, 
        Float mass, 
        Float width,
        Float height, 
        const Vector3& position,
        const Vector3& velocity = Vector3::zero(),
        const Vector3& acceleration = Vector3::zero()
    ) : Mobile(
        name,
        mass,
        width, 
        height,
        position,
        velocity, 
        acceleration
    ) {}
}
