#pragma once
#include "Utility.h"

namespace Core
{
    class ICollisionModel
    {
    public:
        virtual ~ICollisionModel() = default;

        virtual Float getWidth() const = 0;
        virtual void setWidth(Float value) = 0;
        virtual Float getHeight() const = 0;
        virtual void setHeight(Float value) = 0;
    };
}
