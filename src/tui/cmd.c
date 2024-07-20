#include "tui/cmd.h"
#include "stdlib.h"
#include "string.h"

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

void
tui_cmd_clear(WINDOW **cmd)
{
	mvwprintw(*cmd, 1, 9, "                              ");
	wrefresh(*cmd);
}

char *
tui_cmd_get(WINDOW **cmd)
{
	mvwprintw(*cmd, 1, 9, " ");
	wrefresh(*cmd);

	curs_set(1);
	size_t i = 0;
	char comm[64];
	int c;
	while((c = wgetch(*cmd)) != '\n')
	{
		if (c == 27)
		{
			curs_set(0);
			tui_cmd_clear(cmd);
			return 1; 
		}
		
		if (c == 127)
		{
			c = ' ';
        	mvwprintw(*cmd, 1, 9+i, "%c", c);
			i -= 1;
			wmove(*cmd, 1, 10+i);
		}
		else
		{
			comm[i++] = c;
        	mvwprintw(*cmd, 1, 9+i, "%c", c);
		}

		wrefresh(*cmd);
	}
	comm[i] = 0;
	curs_set(0);

	tui_cmd_clear(cmd);

	char *res = (char *)malloc(strlen(comm)+1);
	strcpy(res, comm);

	return res;
	
}