#include "tui/pool.h"


void
tui_pool_init(WINDOW **pool_win)
{
	*pool_win = newwin(7, 20, 3, 50);
	
    box(*pool_win, 0, 0);
    wrefresh(*pool_win);

	init_pair(1, COLOR_BLACK, COLOR_BLUE);	
	init_pair(2, COLOR_WHITE, COLOR_RED);	
	init_pair(3, COLOR_BLACK, COLOR_WHITE);	
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);	
	init_pair(5, COLOR_BLACK, COLOR_GREEN);	

	wattron(*pool_win, COLOR_PAIR(1));
	mvwprintw(*pool_win, 2, 3, " TR ");
	wattron(*pool_win, COLOR_PAIR(2));
	mvwprintw(*pool_win, 2, 8, " TR ");
	wattron(*pool_win, COLOR_PAIR(3));
	mvwprintw(*pool_win, 2, 13, " TR ");
	wattron(*pool_win, COLOR_PAIR(4));
	mvwprintw(*pool_win, 4, 5, " TR ");
	wattron(*pool_win, COLOR_PAIR(5));
	mvwprintw(*pool_win, 4, 11, " TR ");

	wattroff(*pool_win, COLOR_PAIR(5));
	mvwprintw(*pool_win, 0, 2, "POOL");
	wrefresh(*pool_win);
}