#pragma once

#include "Entity.h"
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
            const Vector3& acceleration = Vector3::zero(),
            const Vector3& force = Vector3::zero()
        );

        void onTick(Float msElapsed) override;
        void applyForce(const Vector3& force);

    protected:
        Float mass_;
        Vector3 velocity_;
        Vector3 acceleration_;
        Vector3 force_;
    };
}
