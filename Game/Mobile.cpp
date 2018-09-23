#include "stdafx.h"
#include "Mobile.h"

#include "NewtonMotionModel.h"

namespace Core
{
    Mobile::Mobile(
        const String& name, 
        Float mass,
        const Vector3& position,
        const Vector3& velocity,
        const Vector3& acceleration
    ) : Entity(name, alloc<NewtonMotionModel>(mass, position, velocity, acceleration))
    {}
}
