#include "tui.h"
#include "ncurses.h"
#include "colors.h"

void
tui_init(TUI *tui)
{
	int startx, starty, width, height;
	int ch;

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					//  * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	start_color();
	curs_set(0);


	printw("Press F1 to exit");
	refresh();

	tui_pool_init(tui->pool);


	while((ch = getch()) != KEY_F(1))
	{
	}
		
	endwin();			/* End curses mode		  */
}


void
tui_update(TUI *tui)
{
    refresh();
    getch();
}

void
tui_deinit(TUI *tui)
{
	
    endwin();
}