#pragma once

#include <string>

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
            const Ptr<IMotionModel>& motionModel
        );

        const Vector3& getPosition() const;
        void setPosition(const Vector3& value);

    protected:
        String name_;
        Ptr<IMotionModel> motionModel_;
    };
}
