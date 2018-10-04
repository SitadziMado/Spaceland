#include "stdafx.h"

#include <algorithm>

#include "AabbCollisionModel.h"
#include "IMotionModel.h"
#include "Game.h"
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
        const auto[vx, vy, vz] = lmm.getVelocity().asTuple();

        Vector3 invEntry;
        Vector3 invExit;

        if (vx > 0.)
        { // Moving to the right.
            invEntry.setX(rhs.l - lhs.r);
            invExit.setX(rhs.r - lhs.l);
        }
        else
        { // Moving to the left.
            invEntry.setX(rhs.r - lhs.l);
            invExit.setX(rhs.l - lhs.r);
        }

        if (vy > 0.)
        { // Moving to the right.
            invEntry.setY(rhs.b - lhs.t);
            invExit.setY(rhs.t - lhs.b);
        }
        else
        { // Moving to the left.
            invEntry.setY(rhs.t - lhs.b);
            invExit.setY(rhs.b - lhs.t);
        }

        Vector3 entry;
        Vector3 exit;

        if (vx == 0.)
        {
            entry.setX(-std::numeric_limits<Float>::infinity());
            exit.setX(std::numeric_limits<Float>::infinity());
        }
        else
        {
            entry.setX(invEntry.getX() / vx);
            exit.setX(invExit.getX() / vx);
        }

        if (vy == 0.)
        {
            entry.setY(-std::numeric_limits<Float>::infinity());
            exit.setY(std::numeric_limits<Float>::infinity());
        }
        else
        {
            entry.setY(invEntry.getY() / vy);
            exit.setY(invExit.getY() / vy);
        }

        constexpr auto fps = Game::FramesPerSecond;

        const auto entryTime = std::max(fps * entry.getX(), fps * entry.getY());
        const auto exitTime = std::min(fps * exit.getX(), fps * exit.getY());

        Vector3 normal;

        if (entryTime > exitTime ||
            entry.getX() < 0. && entry.getY() < 0. ||
            entry.getX() > 1. ||
            entry.getY() > 1.
            ) {
            normal = { 0., 0. };
        }
        else // If there was a collision.
        {
            const auto u1 = lmm.getVelocity();
            const auto u2 = rmm.getVelocity();
            const auto m1 = lmm.getMass();
            const auto m2 = rmm.getMass();

            const auto v1 = (u1 * (m1 - m2) + 2. * m2 * u2) / (m1 + m2);
            const auto v2 = (u2 * (m2 - m1) + 2. * m1 * u1) / (m1 + m2);

            lmm.onTick(entryTime / fps);

            lmm.setVelocity(v1);
            rmm.setVelocity(v2);

            /* if (entry.getX() > entry.getY())
            {
                if (invEntry.getX() < 0.0f)
                {
                    normal = { 1., 0. };
                }
                else
                {
                    normal = { -1., 0. };
                }
            }
            else
            {
                if (invEntry.getY() < 0.0f)
                {
                    normal = { 0., 1. };
                }
                else
                {
                    normal = { 0., -1. };
                }
            }

            return entryTime; */
        }
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
