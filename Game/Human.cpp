#include "stdafx.h"
#include "Human.h"

namespace Core
{
    const std::string Human::Name = "Human";

    Human::Human(
        const Vector3& position,
        const Vector3& velocity = Vector3::zero(),
        const Vector3& acceleration = Vector3::zero()
    ) : Actor(Name, Mass, Width, Height, position, velocity, acceleration)
    {}
}
