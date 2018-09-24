#include "stdafx.h"

#include "AabbCollisionModel.h"
#include "IMotionModel.h"
#include "Vector3.h"

namespace Core
{
    AabbCollisionModel::AabbCollisionModel(Float width, Float height)
        : width_(width), height_(height)
    {}

    void AabbCollisionModel::collide(const ICollisionModel& rcm, IMotionModel& lmm, IMotionModel& rmm) const
    {
        const auto lhs = getBounds(lmm);
        const auto rhs = rcm.getBounds(rmm);
        const auto& v = lmm.getVelocity();

        Vector3 invEntry;
        Vector3 invExit;

        // if ()
    }

    AabbCollisionModel::Bounds AabbCollisionModel::getBounds(const IMotionModel& motionModel) const
    {
        const auto [x, y, _] = motionModel.getPosition().asTuple();
        const auto hw = width_ * .5;
        const auto hh = height_ * .5;
        return { x - hw, y - hh, x + hw, y + hh };
    }

    Float AabbCollisionModel::getWidth() const
    {
        return width_;
    }

    void AabbCollisionModel::setWidth(Float value)
    {
        width_ = value;
    }

    Float AabbCollisionModel::getHeight() const
    {
        return height_;
    }

    void AabbCollisionModel::setHeight(Float value)
    {
        height_ = value;
    }
}
