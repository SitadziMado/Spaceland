#include "stdafx.h"
#include "Vector3.h"

namespace Core
{
    Vector3& Vector3::normalize()
    {
        return *this /= length();
    }

    Vector3 Vector3::normalize(const Vector3& value)
    {
        return Vector3(value).normalize();
    }

    Float Vector3::length() const
    {
        return std::sqrt(lengthSq());
    }
}
