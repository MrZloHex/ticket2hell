#ifndef __TRAINS_H__
#define __TRAINS_H__

#include "stdlib.h"
#include "colors.h"


const static size_t k_train_color_quantity = 12;
const static size_t k_locomotive_quantity = 14;

#define POOL_SIZE 5

typedef struct Train_Deck_S
{
    size_t cards[COLORS_QUANTITY];
    size_t locomotives;
    size_t q_cards;

    Color pool[POOL_SIZE];
} Train_Deck;

void
train_deck_init(Train_Deck *deck);

void
train_deck_draw_card(Train_Deck *deck, Color color);

#endif /* __TRAINS_H__ */