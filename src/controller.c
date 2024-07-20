#include "controller.h"
#include "stdio.h"
#include "util.h"

void
ctrl_init(Controller *ctrl)
{
    // parser_init(&(ctrl->parser));
    tui_init(&(ctrl->tui));

}

Color
get_color(int key)
{
    switch (key)
    {
        case 's': return CLR_ROSE;
        case 'w': return CLR_WHITE;
        case 'l': return CLR_BLUE;
        case 'y': return CLR_YELLOW;
        case 'o': return CLR_ORANGE;
        case 'b': return CLR_BLACK;
        case 'r': return CLR_RED;
        case 'g': return CLR_GREEN;
        case 'a': return CLR_ANY;
        default: return CLR_UNKNOWN;
    }
}

bool
ctrl_update(Controller *ctrl, Game *game)
{
    // char input[64];
    // scanf("%s", input);
    // Command cmd = parser_parse(&(ctrl->parser), input);


    Command cmd;
    char name[10];
    // tui_update(&(ctrl->tui));

	int key = tui_get_char(&(ctrl->tui));
    if (key == KEY_F(1))
    {
        return true;
    }
    else if (key == ':')
    {
        tui_cmd_get(&(ctrl->tui.cmd));
    }
    else if (key == 'c')
    {
        int color = getch();
        cmd.type = CMD_ACTION;
        cmd.params.act.type = ACT_DRAW_TRAIN;
        cmd.params.act.params.color = get_color(color);
    }
    // else if (key == 'a')
    // {
    //     scanf("%s", name);
    //     cmd.type = CMD_ADD_PLAYER;
    //     cmd.params.name = name;
    // }
    // else if (key == 's')
    // {
    //     scanf("%s", name);
    //     cmd.type = CMD_SET_FIRST;
    //     cmd.params.name = name;
    // }
    // else if (key == ' ')
    // {
    //     getchar();
    //     game->game_started = true;
    //     return;
    // }
    // else if (key == 27)
    // {
    //     exit(0);
    // }
    // else
    // {
    //     return;
    // }
    
    // ctrl_execute_cmd(ctrl, game, cmd);
    return false;
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
    tui_deinit(&(ctrl->tui));
    // parser_deinit(&(ctrl->parser));
}