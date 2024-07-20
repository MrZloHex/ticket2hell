#ifndef __TUI_CMD_H__
#define __TUI_CMD_H__

#include "ncurses.h"

void
tui_cmd_init(WINDOW **cmd);


int
tui_cmd_get(WINDOW **cmd);

#endif /* __TUI_CMD_H__ */