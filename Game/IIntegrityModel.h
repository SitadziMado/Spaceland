#pragma once

#include "Utility.h"

namespace Core
{
    class DamageBase;

    class IIntegrityModel
    {
    public:
        virtual ~IIntegrityModel() = default;

        virtual void accept(const DamageBase& damage) = 0;

        virtual Float getHitPoints() const = 0;
        virtual void setHitPoints(Float value) = 0;
        virtual Float getArmor() const = 0;
        virtual void setArmor(Float value) = 0;
    };
}
