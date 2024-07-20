#include "stdio.h"
#include "game.h"
#include "controller.h"
#include "tui.h"

int
main(void)
{
    Game game;
    Controller ctrl;

    game_init(&game, 2);
    ctrl_init(&ctrl);

    // printf("TICKET TO HELL!!!!\n");

    bool stop = false;
    while (!stop)
    {
        stop = ctrl_update(&ctrl, &game);
        // stop = game_update(&game);
    }

    // game_deinit(&game);
    ctrl_deinit(&ctrl);

    return 0;
}