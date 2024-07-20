#include "tui/log.h"

void
tui_log_init(WINDOW **log)
{
    // LINES
    // COLS
	*log = newwin(LINES - 6, 40, 3, 5);

    box(*log, 0, 0);
    wrefresh(*log);

	mvwprintw(*log, 0, 2, "LOG");
    size_t win_y, win_x;
    getmaxyx(*log, win_y, win_x);

	init_pair(1, COLOR_BLACK, COLOR_BLUE);	
	init_pair(2, COLOR_WHITE, COLOR_RED);	
	init_pair(3, COLOR_BLACK, COLOR_WHITE);	
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);	
	init_pair(5, COLOR_BLACK, COLOR_GREEN);	

    mvwprintw(*log, win_y - 3, 3, "anya > ");

    mvwprintw(*log, win_y - 3, 11, "DRAW TRAIN CARD ");
    wattron(*log, COLOR_PAIR(4));
    mvwprintw(*log, win_y - 3, 28, " TR ");
    wattroff(*log, COLOR_PAIR(4));

    mvwprintw(*log, win_y - 4, 3, "alex > ");

    mvwprintw(*log, win_y - 4, 11, "DRAW TRAIN CARD ");
    wattron(*log, COLOR_PAIR(5));
    mvwprintw(*log, win_y - 4, 28, " TR ");
    wattroff(*log, COLOR_PAIR(5));


	wattroff(*log, COLOR_PAIR(5));
	wrefresh(*log);
}