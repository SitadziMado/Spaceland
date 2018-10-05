#include "stdafx.h"
#include "Mobile.h"

#include "NewtonMotionModel.h"
#include "AabbCollisionModel.h"

namespace Core
{
    Mobile::Mobile(
        const String& name, 
        Float mass,
        Float width,
        Float height,
        const Vector3& position,
        const Vector3& velocity,
        const Vector3& acceleration
    ) : Entity(
        name,
        alloc<NewtonMotionModel>(mass, position, velocity, acceleration),
        alloc<AabbCollisionModel>(width, height)
    ) {}

    void Mobile::onTick(Float elapsed)
    {
        motionModel_->onTick(elapsed);
    }
}
