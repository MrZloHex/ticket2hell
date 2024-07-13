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
    ctrl_players_next_player(&(game->ctrl_players));
    return true;
}

void
game_claim_route(Game *game, Route route)
{

}

void
game_execute_action(Game *game, Action act)
{
    switch (act.type)
    {
        case ACT_DRAW_TRAIN:
            train_deck_draw_card(&(game->trains), act.params.color);
            break;
        
        case ACT_DRAW_TICKET:
            route_deck_draw_card(game, act.params.route);
            break;

        case ACT_CLAIM_ROUTE:
            game_claim_route(game, act.params.route);
            break;
    }
}

void
game_deinit(Game *game)
{
    ctrl_players_deinit(&(game->ctrl_players));
}