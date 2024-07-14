#include "deck.h"


void
tui_deck_init(WINDOW *deck, char *name, size_t n)
{
	deck = create_newwin(5, 10, 12, 40 + 10*n);
	mvwprintw(deck, 0, 2, name);
    size_t win_y, win_x;
    getmaxyx(deck, win_y, win_x);

	mvwprintw(deck, 2, 4, "97");

	// wattroff(deck, COLOR_PAIR(5));
	wrefresh(deck);
}