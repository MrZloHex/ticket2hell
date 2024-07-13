#include "routes.h"

void
route_deck_init(Route_Deck *deck)
{
    deck->q_cards = k_route_cards;
    deck->cards = route_cards;
}

void
route_deck_draw_card(Route_Deck *deck, Route route)
{
    for (size_t i = 0; i < deck->q_cards; ++i)
    {
        Route_Card card = deck->cards[i];
        if (card.city1 == route.city1 && card.city2 == route.city2)
        {
            if (card.points == 0)
            { exit(1); }

            deck->cards[i].points = 0;
        }
    }
    
    exit(1);
}