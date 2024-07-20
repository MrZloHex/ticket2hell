#include "tui/cmd.h"

void
tui_cmd_init(WINDOW *cmd)
{
	cmd = create_newwin(3, COLS-60, LINES-6, 50);
	mvwprintw(cmd, 0, 2, "CMD");
    size_t win_y, win_x;
    getmaxyx(cmd, win_y, win_x);

	init_pair(1, COLOR_BLACK, COLOR_BLUE);	
	init_pair(2, COLOR_WHITE, COLOR_RED);	
	init_pair(3, COLOR_BLACK, COLOR_WHITE);	
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);	
	init_pair(5, COLOR_BLACK, COLOR_GREEN);	

    mvwprintw(cmd, 1, 3, "anya > ");

	wrefresh(cmd);
}