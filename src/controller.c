#include "controller.h"
#include "stdio.h"
#include "util.h"

void
ctrl_init(Controller *ctrl)
{
    // parser_init(&(ctrl->parser));
}

Color
get_color(int key)
{
    switch (key)
    {
        case 's': return COLOR_ROSE;
        case 'w': return COLOR_WHITE;
        case 'l': return COLOR_BLUE;
        case 'y': return COLOR_YELLOW;
        case 'o': return COLOR_ORANGE;
        case 'b': return COLOR_BLACK;
        case 'r': return COLOR_RED;
        case 'g': return COLOR_GREEN;
        case 'a': return COLOR_ANY;
        default: return COLOR_UNKNOWN;
    }
}

void
ctrl_update(Controller *ctrl, Game *game)
{
    // char input[64];
    // scanf("%s", input);
    // Command cmd = parser_parse(&(ctrl->parser), input);

    Command cmd;
    char name[10];
    int key = getchar();
    if (key == 'c')
    {
        int color = getchar();
        getchar();
        cmd.type = CMD_ACTION;
        cmd.params.act.type = ACT_DRAW_TRAIN;
        cmd.params.act.params.color = get_color(color);
    }
    else if (key == 'a')
    {
        scanf("%s", name);
        cmd.type = CMD_ADD_PLAYER;
        cmd.params.name = name;
    }
    else if (key == 's')
    {
        scanf("%s", name);
        cmd.type = CMD_SET_FIRST;
        cmd.params.name = name;
    }
    else if (key == ' ')
    {
        getchar();
        game->game_started = true;
        return;
    }
    else if (key == 27)
    {
        exit(0);
    }
    else
    {
        return;
    }
    
    ctrl_execute_cmd(ctrl, game, cmd);
}

void
ctrl_execute_cmd(Controller *ctrl, Game *game, Command cmd)
{
    switch (cmd.type)
    {
        case CMD_ADD_PLAYER:
            printf("ADD NEW PLAYER %s\n", cmd.params.name);
            ctrl_players_add_player(&(game->ctrl_players), cmd.params.name);
            break;
        case CMD_SET_FIRST:
            printf("PLAYER %s IS FIRST\n", cmd.params.name);
            ctrl_players_set_first(&(game->ctrl_players), cmd.params.name);
            break;
        case CMD_ACTION:
            game_execute_action(game, cmd.params.act);
            break;
    }
}

void
ctrl_deinit(Controller *ctrl)
{
    // parser_deinit(&(ctrl->parser));
}