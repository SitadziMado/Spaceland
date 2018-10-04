#include "stdafx.h"
#include "NewtonMotionModel.h"

#include <vector>

namespace Core
{
    NewtonMotionModel::NewtonMotionModel(
        Float mass, 
        const Vector3& position, 
        const Vector3& velocity,
        const Vector3& acceleration
    ) : mass_(mass), position_(position), velocity_(velocity), acceleration_(acceleration)
    {}

    void NewtonMotionModel::onTick(Float elapsed)
    {
        accumulateAcceleration(elapsed);
        velocity_ += acceleration_ * elapsed;
        position_ += velocity_ * elapsed;
    }

    void NewtonMotionModel::applyForce(const Force& force)
    {
        forces_.push_back(force);
    }

    const Float& NewtonMotionModel::getMass() const
    {
        return mass_;
    }

    void NewtonMotionModel::setMass(Float value)
    {
        mass_ = value;
    }

    const Vector3& NewtonMotionModel::getPosition() const
    {
        return position_;
    }

    void NewtonMotionModel::setPosition(const Vector3& value)
    {
        position_ = value;
    }

    const Vector3& NewtonMotionModel::getVelocity() const
    {
        return velocity_;
    }

    void NewtonMotionModel::setVelocity(const Vector3& value)
    {
        velocity_ = value;
    }

    const Vector3& NewtonMotionModel::getAcceleration() const
    {
        return acceleration_;
    }

    void NewtonMotionModel::setAcceleration(const Vector3& value)
    {
        acceleration_ = value;
    }

    void NewtonMotionModel::accumulateAcceleration(Float elapsed)
    {
        acceleration_ = Vector3::zero();

        std::vector<decltype(forces_)::iterator> forRemoval;

        for (auto it = forces_.begin(); it != forces_.end(); ++it)
        {
            it->apply(acceleration_, elapsed);

            if (it->isExpired())
            {
                forRemoval.push_back(it);
            }
        }

        for (auto&& removal : forRemoval)
        {
            forces_.erase(removal);
        }
    }
}