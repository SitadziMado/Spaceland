#pragma once

#include "Actor.h"

namespace Core
{
    class Human final : public Actor
    {
    public:
        static constexpr Float Mass = 1.;
        static constexpr Float Width = 1.;
        static constexpr Float Height = 1.;
        static const std::string Name;

        Human(
            const Vector3& position,
            const Vector3& velocity,
            const Vector3& acceleration
        );
    };
}
