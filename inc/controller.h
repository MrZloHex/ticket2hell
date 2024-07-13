#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "actions.h"
#include "parser.h"
#include "game.h"


typedef struct Controller_S
{
    Parser parser;
} Controller;

void
ctrl_init(Controller *ctrl);

void
ctrl_update(Controller *ctrl, Game *game);

void
ctrl_deinit(Controller *ctrl);

#endif /* __CONTROLLER_H__ */