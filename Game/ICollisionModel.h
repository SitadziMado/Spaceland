#pragma once
#include "Utility.h"

namespace Core
{
    class IMotionModel;

    class ICollisionModel
    {
    public:
        struct Bounds;

        virtual ~ICollisionModel() = default;

        virtual void collide(
            const ICollisionModel& rcm,
            IMotionModel& lmm, 
            IMotionModel& rmm
        ) const = 0;
        virtual Bounds getBounds(const IMotionModel& motionModel) const = 0;

        virtual Float getWidth() const = 0;
        virtual void setWidth(Float value) = 0;
        virtual Float getHeight() const = 0;
        virtual void setHeight(Float value) = 0;
    };

    struct ICollisionModel::Bounds
    {
        Bounds(Float left, Float top, Float width, Float height);
        const Float l, t, r, b;
    };
}
