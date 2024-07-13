#ifndef __GAME_H__
#define __GAME_H__

#include "map.h"
#include "trains.h"
#include "routes.h"


typedef struct Game_S
{
    Map map;
    Train_Deck trains;
    Route_Deck routs;
} Game;

#endif /* __GAME_H__ */