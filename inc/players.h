#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "stdlib.h"

#define MAX_PLAYERS 5

typedef struct Player_S
{
    char *name;
    size_t points;
} Player;

typedef struct
{
    Player *players;
    size_t q_players;

    size_t curr_player;
} Controller_Players;


void
ctrl_players_init(Controller_Players *ctrl, size_t q_players);

void
ctrl_players_add_player(Controller_Players *ctrl, char *name);

void
ctrl_players_set_first(Controller_Players *ctrl, char *name);

void
ctrl_players_next_player(Controller_Players *ctrl);

char *
ctrl_players_get_curr_name(Controller_Players *ctrl);

size_t
ctrl_players_get_curr_points(Controller_Players *ctrl);

void
ctrl_players_deinit(Controller_Players *ctrl);


#endif /* __PLAYER_H__ */