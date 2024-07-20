#ifndef __TUI_H__
#define __TUI_H__

#include "tui/pool.h"
#include "tui/log.h"
#include "tui/deck.h"
#include "tui/cmd.h"
#include "tui/player.h"
#include "players.h"

typedef struct TUI_S
{
    WINDOW *pool;
    WINDOW *log;
    WINDOW *card_deck;
    WINDOW *train_deck;
    WINDOW *cmd;
    WINDOW *player[MAX_PLAYERS];
} TUI;

void
tui_init(TUI *tui);

int
tui_get_char(TUI *tui);

void
tui_update(TUI *tui);

void
tui_deinit(TUI *tui);

#endif /* __TUI_H__ */