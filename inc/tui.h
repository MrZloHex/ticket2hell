#ifndef __TUI_H__
#define __TUI_H__

// #include "ncurses.h"
#include "tui/pool.h"
#include "tui/log.h"
#include "tui/deck.h"
#include "tui/cmd.h"

typedef struct TUI_S
{
    WINDOW *pool;
    WINDOW *log;
    WINDOW *card_deck;
    WINDOW *train_deck;
    WINDOW *cmd;
} TUI;

void
tui_init(TUI *tui);

void
tui_update(TUI *tui);

void
tui_deinit(TUI *tui);

#endif /* __TUI_H__ */