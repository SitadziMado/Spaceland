#pragma once

#include "ICollisionModel.h"

namespace Core
{
    class AabbCollisionModel final : public ICollisionModel
    {
    public:
        AabbCollisionModel(Float width, Float height);

        void collide(const ICollisionModel& rcm, IMotionModel& lmm, IMotionModel& rmm) const override;
        Bounds getBounds(const IMotionModel& motionModel) const override;

        Float getWidth() const override;
        void setWidth(Float value) override;
        Float getHeight() const override;
        void setHeight(Float value) override;

    private:
        Float width_;
        Float height_;
    };
}