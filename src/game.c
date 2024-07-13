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
    if (game->game_started)
    {
        printf("%s >", ctrl_players_get_curr_name(&(game->ctrl_players)));
        ctrl_players_next_player(&(game->ctrl_players));
    }
    return false;
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
            printf(" > DRAWING TRAIN CARD \033[38;5;37m\033[48;5;%dm%s\033[0m\n", k_colors_esc[act.params.color], k_colors_s[act.params.color]);
            train_deck_draw_card(&(game->trains), act.params.color);
            break;
        
        case ACT_DRAW_TICKET:
            // printf(" > DRAWING TICKET CARD %s -> %s\n", k_colors_esc[act.params.color], k_colors_s[act.params.color]);
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