#pragma once

#include "World.h"

#include <mutex>
#include <thread>

namespace Core
{
    class Game
    {
    public:
        static constexpr Int FramesPerSecond = 60;
        static constexpr Float FrameSeconds = 1. / FramesPerSecond;
        static constexpr Float FrameMilliseconds = 1000. / FramesPerSecond;

        Game();

        void start();
        void pause();
        void stop();
        void onTick(Float msElapsed);

        void createEntity(const std::string& name);

        bool isAlive() const noexcept;

    private:
        bool live_;
        bool running_;
        std::thread gameLogicThread_;
        // std::thread renderThread_;

        // std::mutex worldMutex_;
    public: World world_;
    };
}