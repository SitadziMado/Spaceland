#pragma once

#include <string>

#include "ITickable.h"
#include "Vector3.h"
#include "ICollisionModel.h"

namespace Core
{
    class IMotionModel;

    class Entity : public ITickable
    {
    public:
        Entity(
            const String& name, 
            const Ptr<IMotionModel>& motionModel,
            const Ptr<ICollisionModel>& collisionModel
        );

        void collide(const Entity& rhs);

        const Vector3& getPosition() const;
        void setPosition(const Vector3& value);

    protected:
        String name_;
        Ptr<IMotionModel> motionModel_;
        Ptr<ICollisionModel> collisionModel_;
    };
}
