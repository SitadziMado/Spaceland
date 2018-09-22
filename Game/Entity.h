#pragma once

#include <string>

#include "ITickable.h"
#include "Vector3.h"

namespace Core
{
    class Entity : public ITickable
    {
    public:
        Entity(const String& name, const Vector3& position);

    protected:
        String name_;
        Vector3 position_;
    };
}
