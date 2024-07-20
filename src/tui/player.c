#include "tui/player.h"

void
tui_player_init(WINDOW *player, char *name, size_t n)
{
    player = create_newwin(20, 50, 3, 75+n*60);
	mvwprintw(player, 0, 2, "%s", name);
    size_t win_y, win_x;
    getmaxyx(player, win_y, win_x);

	init_pair(1, COLOR_BLACK, COLOR_BLUE);	
	init_pair(2, COLOR_WHITE, COLOR_RED);	
	init_pair(3, COLOR_BLACK, COLOR_WHITE);	
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);	
	init_pair(5, COLOR_BLACK, COLOR_GREEN);	

    // mvwprintw(player, 1, 3, "anya > ");

	wrefresh(player);
}