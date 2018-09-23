#pragma once

#include "Vector3.h"

namespace Core
{
    class Mobile;

    class Force
    {
    public:
        Force(Float duration, const Vector3& vector);

        void apply(Vector3& acceleration, Float elapsed);
        bool isExpired() const;

    private:
        Float duration_;
        Vector3 vector_;
    };
}
