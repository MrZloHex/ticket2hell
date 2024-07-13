#ifndef __GAME_H__
#define __GAME_H__

#include "map.h"
#include "trains.h"
#include "routes.h"
#include "players.h"
#include "actions.h"

#include "stdbool.h"

typedef struct Game_S
{
    Map map;
    Train_Deck trains;
    Route_Deck routes;

    bool game_started;

    Controller_Players ctrl_players;
} Game;


void
game_init(Game *game, size_t q_players);

bool
game_update(Game *game);

void
game_draw_train_card(Game *game, Color clr);

void
game_execute_action(Game *game, Action act);

void
game_deinit(Game *game);

#endif /* __GAME_H__ */