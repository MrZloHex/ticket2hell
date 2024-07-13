#include "players.h"
#include "string.h"

void
ctrl_players_init(Controller_Players *ctrl, size_t q_players)
{
    if (q_players > MAX_PLAYERS)
    { exit(1); }

    ctrl->players = (Player *)malloc(sizeof(Player) * q_players);
    if (!ctrl->players)
    { exit(1); }

    ctrl->q_players = q_players;
    ctrl->curr_player = 0;
}

void
ctrl_players_add_player(Controller_Players *ctrl, char *name)
{
    if (ctrl->curr_player == ctrl->q_players)
    { exit(1); }

    ctrl->players[ctrl->curr_player].points = 0;

    ctrl->players[ctrl->curr_player].name = 
        (char *)malloc(strlen(name) + 1);
    if (!ctrl->players[ctrl->curr_player].name)
    { exit(1); }

    strcpy(ctrl->players[ctrl->curr_player].name, name);
    ++ctrl->curr_player;
}

void
ctrl_players_set_first(Controller_Players *ctrl, char *name)
{
    for (size_t i = 0; i < ctrl->q_players; ++i)
    {
        if (strcmp(name, ctrl->players[i].name) == 0)
        {
            ctrl->curr_player = i; 
            return;
        }
    }
    exit(1);
}

void
ctrl_players_next_player(Controller_Players *ctrl)
{
    size_t c = ctrl->curr_player;
    ctrl->curr_player = ++c == ctrl->q_players ? 0 : c;
    
}

char *
ctrl_players_get_curr_name(Controller_Players *ctrl)
{
    return ctrl->players[ctrl->curr_player].name;
}

size_t
ctrl_players_get_curr_points(Controller_Players *ctrl)
{
    return ctrl->players[ctrl->curr_player].points;
}


void
ctrl_players_deinit(Controller_Players *ctrl)
{
    if (!ctrl->players)
    { free(ctrl->players); }
}