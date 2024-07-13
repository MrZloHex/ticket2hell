#include "stdio.h"
#include "game.h"

int
main(void)
{
    Game game;
    game_init(&game);

    printf("TICKET TO HELL!!!!\n");

    bool stop = false;
    while (!stop)
    {
        stop = game_update(&game);
    }

    game_deinit(&game);
    return 0;
}