#include "controller.h"

void
ctrl_init(Controller *ctrl)
{
    parser_init(&(ctrl->parser));
}

void
ctrl_update(Controller *ctrl)
{
    
}

void
ctrl_deinit(Controller *ctrl)
{
    parser_deinit(&(ctrl->parser));
}