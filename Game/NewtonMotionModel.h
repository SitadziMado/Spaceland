#pragma once

#include <list>

#include "Force.h"
#include "IMotionModel.h"
#include "Vector3.h"

namespace Core
{
    class NewtonMotionModel final : public IMotionModel
    {
    public:
        NewtonMotionModel(
            Float mass,
            const Vector3& position,
            const Vector3& velocity = Vector3::zero(),
            const Vector3& acceleration = Vector3::zero()
        );

        void onTick(Float elapsed) override;
        void applyForce(const Force& force) override;

        const Float& getMass() const override;
        void setMass(Float value) override;
        const Vector3& getPosition() const override;
        void setPosition(const Vector3& value) override;
        const Vector3& getVelocity() const override;
        void setVelocity(const Vector3& value) override;
        const Vector3& getAcceleration() const override;
        void setAcceleration(const Vector3& value) override;

    private:
        void accumulateAcceleration(Float elapsed);

        Float mass_;
        Vector3 position_;
        Vector3 velocity_;
        Vector3 acceleration_;
        std::list<Force> forces_{};
    };
}
