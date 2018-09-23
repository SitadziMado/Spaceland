#include "stdafx.h"
#include "ForceManager.h"
#include <vector>

namespace Core
{
    ForceManager& ForceManager::applyForce(const Force& force)
    {
        forces_.push_back(force);
        return *this;
    }

    ForceManager& ForceManager::apply(Mobile& mobile, Float elapsed)
    {
        std::vector<decltype(forces_)::iterator> forRemoval;

        for (auto it = forces_.begin(); it != forces_.end(); ++it)
        {
            it->apply(mobile, elapsed);

            if (it->isExpired())
            {
                forRemoval.push_back(it);
            }
        }

        for (auto&& removal : forRemoval)
        {
            forces_.erase(removal);
        }

        return *this;
    }
}
