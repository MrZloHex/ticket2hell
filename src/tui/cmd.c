#include "tui/cmd.h"

void
tui_cmd_init(WINDOW **cmd)
{
    *cmd = newwin(3, COLS-50, LINES-6, 50);
	
    box(*cmd, 0, 0);
    wrefresh(*cmd);

	mvwprintw(*cmd, 0, 2, "CMD");
    size_t win_y, win_x;
    getmaxyx(*cmd, win_y, win_x);

	init_pair(1, COLOR_BLACK, COLOR_BLUE);	
	init_pair(2, COLOR_WHITE, COLOR_RED);	
	init_pair(3, COLOR_BLACK, COLOR_WHITE);	
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);	
	init_pair(5, COLOR_BLACK, COLOR_GREEN);	

    mvwprintw(*cmd, 1, 3, "anya >");
	wrefresh(*cmd);
}

int
tui_cmd_get(WINDOW **cmd)
{
	mvwprintw(*cmd, 1, 9, " ");
	wrefresh(*cmd);

	curs_set(1);
	size_t i = 0;
	char comm[64];
	char c;
	while((c = (char)wgetch(*cmd)) != '\n')
	{
		mvwprintw(*cmd, 1, 10+i, "%c", c);
		wrefresh(*cmd);
		comm[i++] = c;
	}
	comm[i] = 0;
	curs_set(0);
}