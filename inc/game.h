#ifndef __GAME_H__
#define __GAME_H__

#include "map.h"
#include "trains.h"
#include "routes.h"
#include "stdbool.h"

typedef struct Game_S
{
    Map map;
    Train_Deck trains;
    Route_Deck routs;
} Game;

void
game_init(Game *game);

bool
game_update(Game *game);

void
game_deinit(Game *game);

#endif /* __GAME_H__ */