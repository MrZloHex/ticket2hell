#ifndef __TUI_WINDOWS_H__
#define __TUI_WINDOWS_H__

#include "ncurses.h"

WINDOW *
create_newwin(int height, int width, int starty, int startx);

void
destroy_win(WINDOW *local_win);


#endif /* __TUI_WINDOWS_H__ */