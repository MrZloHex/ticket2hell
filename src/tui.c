#include "tui.h"
#include "ncurses.h"
#include "colors.h"

void
tui_init(TUI *tui)
{

	initscr();
	// raw();
	cbreak();
	keypad(stdscr, TRUE);
	start_color();
	noecho();
	curs_set(0);


	printw("Press F1 to exit");
	refresh();

	tui_pool_init(&(tui->pool));
	tui_log_init(&(tui->log));
	tui_deck_init(&(tui->card_deck), "TRAINS", 1);
	tui_deck_init(&(tui->card_deck), "ROUTES", 2);
	tui_player_init(&(tui->player[0]), "ANYA", 0);
	tui_player_init(&(tui->player[1]), "ALEX", 1);
	tui_cmd_init(&(tui->cmd));
}


void
tui_update(TUI *tui)
{
}

int
tui_get_char(TUI *tui)
{
	refresh();
	return getch();
}

void
tui_deinit(TUI *tui)
{
    endwin();
}