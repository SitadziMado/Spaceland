#pragma once

#include "ITickable.h"
#include "Utility.h"

namespace Core
{
    class Force;
    class Vector3;

    class IMotionModel : ITickable
    {
    public:
        virtual ~IMotionModel() = default;

        virtual void applyForce(const Force& force) = 0;

        virtual const Float& getMass() const = 0;
        virtual void setMass(Float value) = 0;
        virtual const Vector3& getPosition() const = 0;
        virtual void setPosition(const Vector3& value) = 0;
        virtual const Vector3& getVelocity() const = 0;
        virtual void setVelocity(const Vector3& value) = 0;
        virtual const Vector3& getAcceleration() const = 0;
        virtual void setAcceleration(const Vector3& value) = 0;
    };
}