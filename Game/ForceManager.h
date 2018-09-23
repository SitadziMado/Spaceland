#pragma once

#include "Force.h"

#include <list>

namespace Core
{
    class ForceManager
    {
    public:
        ForceManager& applyForce(const Force& force);
        ForceManager& apply(Mobile& mobile, Float elapsed);

    private:
        std::list<Force> forces_;
    };
}
