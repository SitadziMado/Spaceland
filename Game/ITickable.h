﻿#pragma once

#include "Utility.h"

namespace Core
{
    class ITickable
    {
    public:
        virtual ~ITickable() = default;

        virtual void onTick(Float msElapsed) = 0;
    };
}
