#include "stdafx.h"
#include "Game.h"
#include <iostream>

namespace Core
{
    Game::Game()
        : live_(false), running_(false)
    {}

    void Game::start()
    {
        /* using namespace std::chrono;
        using namespace std::chrono_literals;
        using namespace std::this_thread;

        auto now = []() {
            return high_resolution_clock::now();
        };

        live_ = true;
        running_ = true;

        gameLogicThread_ = std::thread([this, &now]() {
            const auto delta = milliseconds(static_cast<Int>(FrameMilliseconds));
            auto previousTimePoint = now();
            auto currentTimePoint = previousTimePoint;

            while (live_)
            {
                if (running_)
                {
                    currentTimePoint = now();

                    if (currentTimePoint > previousTimePoint + delta)
                    {
                        const auto elapsed = 
                            duration_cast<nanoseconds>(currentTimePoint - previousTimePoint).count() /
                            1'000'000.;

                        previousTimePoint = currentTimePoint;

                        // std::lock_guard<std::mutex> worldLockGuard(worldMutex_);
                        // ToDo: обязательно сделать потокобезопасным.
                        onTick(elapsed);
                    }
                    else
                    {
                        // ToDo: возможно, стоит поправить...
                        // sleep_for(1ms);
                        sleep_until(previousTimePoint + delta / 4);
                    }
                }
                else
                {
                    // ToDo: сделать точнее.
                    previousTimePoint = now();
                    sleep_for(100ms);
                }
            }
        }); */
    }

    void Game::pause()
    {
        running_ = !running_;
    }

    void Game::stop()
    {
        live_ = false;
        gameLogicThread_.join();
    }

    bool Game::isAlive() const noexcept
    {
        return live_;
    }

    void Game::onTick(Float msElapsed)
    {
        world_.onTick(msElapsed * .001);
        std::cout << msElapsed << std::endl;
    }

    void Game::createEntity(const std::string& name)
    {
        world_.createEntity(name);
    }
}
