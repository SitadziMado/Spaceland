#pragma once

#include <string>

#include "ICollisionModel.h"
#include "IRenderingModel.h"
#include "ITickable.h"
#include "Vector3.h"

namespace Core
{
    class IMotionModel;

    class Entity : public ITickable
    {
    public:
        Entity(
            const String& name, 
            const Ptr<IMotionModel>& motionModel,
            const Ptr<ICollisionModel>& collisionModel /*,
            const Ptr<IRenderingModel>& renderingModel */
        );

        void collide(const Entity& rhs);

        const Vector3& getPosition() const;
        void setPosition(const Vector3& value);
        const Vector3& getAcceleration() const;
        void setAcceleration(const Vector3& value);

    protected:
        String name_;
        Ptr<IMotionModel> motionModel_;
        Ptr<ICollisionModel> collisionModel_;
        Ptr<IRenderingModel> renderingModel_;
    };
}
