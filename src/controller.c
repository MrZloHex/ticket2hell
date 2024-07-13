#include "controller.h"
#include "stdio.h"

void
ctrl_init(Controller *ctrl)
{
    // parser_init(&(ctrl->parser));
}

void
ctrl_update(Controller *ctrl, Game *game)
{
    char input[64];
    scanf("%s", input);
    // Command cmd = parser_parse(&(ctrl->parser), input);
    Command cmd = { .type = CMD_ADD_PLAYER, .params.name = "ALEX" };
    
    ctrl_execute_cmd(ctrl, game, cmd);
}

void
ctrl_execute_cmd(Controller *ctrl, Game *game, Command cmd)
{
    switch (cmd.type)
    {
        case CMD_ADD_PLAYER:
            ctrl_players_add_player(&(game->ctrl_players), cmd.params.name);
            break;
        case CMD_SET_FIRST:
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