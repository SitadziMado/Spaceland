﻿#include "stdafx.h"
#include "Game.h"

namespace Core
{
    Game::Game()
        : live_(false), running_(false)
    {}

    void Game::start()
    {
        using namespace std::chrono;
        using namespace std::chrono_literals;
        using namespace std::this_thread;

        gameLogicThread_ = std::thread([this]() {
            const auto delta = milliseconds(static_cast<Int>(FrameMilliseconds * 1000.));
            auto previousTimePoint = high_resolution_clock::now();
            auto nextTimePoint = high_resolution_clock::now() + delta;

            while (live_)
            {
                if (running_)
                {
                    auto currentTimePoint = high_resolution_clock::now();

                    if (currentTimePoint > nextTimePoint)
                    {
                        const auto elapsed = 
                            duration_cast<nanoseconds>(currentTimePoint - previousTimePoint).count() /
                            1000000.;

                        previousTimePoint = currentTimePoint;

                        std::lock_guard<std::mutex> worldLockGuard(worldMutex_);
                        onTick(elapsed);

                        nextTimePoint += delta;
                    }
                    else
                    {
                        // ToDo: возможно, стоит поправить...
                        sleep_until(nextTimePoint);
                    }
                }
                else
                {
                    sleep_for(100ms);
                }
            }
        });
    }

    void Game::pause()
    {
        running_ = false;
    }

    void Game::stop()
    {
        live_ = false;
    }

    void Game::onTick(Float msElapsed)
    {
        world_.onTick(msElapsed);
    }
}
