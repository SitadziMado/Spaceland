#include "stdafx.h"

#include "Game.h"
#include <iostream>

using namespace Core;

int main()
{
    using namespace std::chrono_literals;
    using namespace std::this_thread;

    auto game = Game();

    game.start();

    std::string input;

    while (game.isAlive())
    {
        std::getline(std::cin, input);

        if (input == "exit")
        {
            game.stop();
            sleep_for(500ms);
        }
        else if (input == "pause")
        {
            game.pause();
        }
    }

    return 0;
}
