﻿#pragma once

#include "World.h"

#include <mutex>
#include <thread>

namespace Core
{
    class Game
    {
    public:
        Game();

        void start();
        void pause();
        void stop();

    private:
        static constexpr Int FramesPerSecond = 60;
        static constexpr Float FrameSeconds = 1. / FramesPerSecond;
        static constexpr Float FrameMilliseconds = 1000. / FramesPerSecond;

        void onTick(Float msElapsed);

        bool live_;
        bool running_;
        std::thread gameLogicThread_;
        // std::thread renderThread_;

        std::mutex worldMutex_;
        World world_;
    };
}