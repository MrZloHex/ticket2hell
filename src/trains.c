#include "trains.h"

void
train_deck_init(Train_Deck *deck)
{
    deck->locomotives = k_locomotive_quantity;
    deck->q_cards = k_locomotive_quantity + COLORS_QUANTITY * k_train_color_quantity;
    for (size_t i = 0; i < COLORS_QUANTITY; ++i)
    { deck->cards[i] = k_train_color_quantity; }
}

void
train_deck_draw_card(Train_Deck *deck, Color color)
{
    if (color == COLOR_ANY)
    { --deck->locomotives; }
    else if (color < COLORS_QUANTITY)
    { --deck->cards[color]; }
    
    --deck->q_cards;
}