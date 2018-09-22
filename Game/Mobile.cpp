#include "stdafx.h"
#include "Mobile.h"

namespace Core
{
    Mobile::Mobile(
        const String& name, 
        Float mass,
        const Vector3& position,
        const Vector3& velocity,
        const Vector3& acceleration, 
        const Vector3& force
    ) : Entity(name, position),
        mass_(mass),
        velocity_(velocity),
        acceleration_(acceleration),
        force_(force)
    {}

    void Mobile::onTick(Float msElapsed)
    {
        const auto secondsElapsed = msElapsed / 1000.;

        acceleration_ = force_ / mass_;
        velocity_ += acceleration_ * secondsElapsed;
        position_ += velocity_ * secondsElapsed;
    }

    void Mobile::applyForce(const Vector3& force)
    {
        force_ = force;
    }
}
