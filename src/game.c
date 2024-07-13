#include "game.h"

void
game_init(Game *game, size_t q_players)
{
    game->game_started = false;
    ctrl_players_init(&(game->ctrl_players), q_players);
}

bool
game_update(Game *game)
{
    return true;
}

void
game_deinit(Game *game)
{
    ctrl_players_deinit(&(game->ctrl_players));
}