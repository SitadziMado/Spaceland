#pragma once

#include <vector>

#include "Entity.h"

namespace Core
{
    class World : public ITickable
    {
    public:
        void onTick(Float elapsed) override;

        void createEntity(const String& name);
        void destroyEntity(const Ptr<Entity>& entity);

    private:
        std::vector<Ptr<Entity>> entities_{};
    };
}
