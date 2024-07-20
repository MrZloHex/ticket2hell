#include "ncurses.h"
#include "stdio.h"
#include "stdlib.h"


// WINDOW *
// create_newwin(int height, int width, int starty, int startx)
// {
// 	WINDOW *local_win;
//     exit(69);

// 	local_win = newwin(height, width, starty, startx);
// 	box(local_win, 0, 0);
//     wprintw(local_win, "HUY");
// 	wrefresh(local_win);

// 	return local_win;
// }

// void destroy_win(WINDOW *local_win)
// {	
// 	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
// 	wrefresh(local_win);
// 	delwin(local_win);
// }

typedef WINDOW *WIN;

typedef struct
{
    WIN win;
    WIN v;
} CTRL;

void
c_n(CTRL *c)
{
    // c->win = create_newwin(10, 10, 10, 10);
    _n(&(c->win));
}

void
_n(WIN *w)
{
    *w = newwin(10, 10, 10, 10);
    keypad(*w, TRUE);
    box(*w, 0, 0);
    refresh();
    wrefresh(*w);

}

void
c_p(CTRL *c, int k)
{
    _p(&(c->win), k);
}

void
_p(WIN *w, int k)
{
    mvwprintw(*w, 1, 1, "%c", (char)k);
    wrefresh(*w);
}

int
c_g(CTRL *c)
{
    return wgetch(c->win);
}

void
c_d(CTRL *c)
{
    delwin(c->win);
}

int
main(void)
{

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	start_color();
	noecho();
    // curs_set(0);

    CTRL c;
    c_n(&c);

    // c_p(&c);

    int key;
    while((key = c_g(&c)) != KEY_F(1))
    {
        c_p(&c, key);
    }

    c_d(&c);
    // delwin(win);
    endwin();
    return 0;
}

// #define WIDTH 30
// #define HEIGHT 10 

// int startx = 0;
// int starty = 0;

// char *choices[] = { 
// 			"Choice 1",
// 			"Choice 2",
// 			"Choice 3",
// 			"Choice 4",
// 			"Exit",
// 		  };
// int n_choices = sizeof(choices) / sizeof(char *);
// void print_menu(WINDOW *menu_win, int highlight);

// int main()
// {	WINDOW *menu_win;
// 	int highlight = 1;
// 	int choice = 0;
// 	int c;

// 	initscr();
// 	clear();
// 	noecho();
// 	cbreak();	/* Line buffering disabled. pass on everything */
// 	startx = (80 - WIDTH) / 2;
// 	starty = (24 - HEIGHT) / 2;
		
// 	// menu_win = newwin(HEIGHT, WIDTH, starty, startx);
//     menu_win = create_newwin(HEIGHT, WIDTH, starty, startx);
// 	keypad(menu_win, TRUE);
// 	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
// 	refresh();
// 	print_menu(menu_win, highlight);
// 	while(1)
// 	{	c = wgetch(menu_win);
// 		switch(c)
// 		{	case KEY_UP:
// 				if(highlight == 1)
// 					highlight = n_choices;
// 				else
// 					--highlight;
// 				break;
// 			case KEY_DOWN:
// 				if(highlight == n_choices)
// 					highlight = 1;
// 				else 
// 					++highlight;
// 				break;
// 			case 10:
// 				choice = highlight;
// 				break;
// 			default:
// 				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
// 				refresh();
// 				break;
// 		}
// 		print_menu(menu_win, highlight);
// 		if(choice != 0)	/* User did a choice come out of the infinite loop */
// 			break;
// 	}	
// 	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
// 	clrtoeol();
// 	refresh();
// 	endwin();
// 	return 0;
// }


// void print_menu(WINDOW *menu_win, int highlight)
// {
// 	int x, y, i;	

// 	x = 2;
// 	y = 2;
// 	// box(menu_win, 0, 0);
// 	for(i = 0; i < n_choices; ++i)
// 	{	if(highlight == i + 1) /* High light the present choice */
// 		{	wattron(menu_win, A_REVERSE); 
// 			mvwprintw(menu_win, y, x, "%s", choices[i]);
// 			wattroff(menu_win, A_REVERSE);
// 		}
// 		else
// 			mvwprintw(menu_win, y, x, "%s", choices[i]);
// 		++y;
// 	}
// 	wrefresh(menu_win);
// }