#include "stdafx.h"
#include "Force.h"

#include "Mobile.h"

namespace Core
{
    Force::Force(Float duration, const Vector3& vector)
        : duration_(duration), vector_(vector)
    {}

    void Force::apply(Vector3& acceleration, Float elapsed)
    {
        if (duration_ > elapsed)
        {
            duration_ -= elapsed;
        }
        else
        {
            elapsed = duration_;
            duration_ = 0.;
        }

        acceleration += vector_ * elapsed;
    }

    bool Force::isExpired() const
    {
        return duration_ == 0.;
    }
}
