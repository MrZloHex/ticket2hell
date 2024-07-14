#ifndef __ROUTES_H__
#define __ROUTES_H__

#include "stdlib.h"
#include "colors.h"

typedef enum City_E
{
    CITY_WANCOUVER,
    CITY_SEATTLE,
    CITY_PORTLAND,
    CITY_SAN_FRANCISCO,
    CITY_LOS_ANGELOS,
    CITY_EL_PASO,
    CITY_HOUSTON,
    CITY_NEW_ORLEANS,
    CITY_MIAMI,
    CITY_CHARLESTON,
    CITY_RALIEGH,
    CITY_WASHINGTON,
    CITY_NEW_YORK,
    CITY_BOSTON,
    CITY_MONTREAL,
    CITY_SAULT_ST_MARIE,
    CITY_WINNIPEG,
    CITY_CALGARY,
    CITY_HELENA,
    CITY_DULUTH,
    CITY_TORONTO,
    CITY_PITTSBURGH,
    CITY_CHICAGO,
    CITY_OMAHA,
    CITY_DENVER,
    CITY_SALT_LAKE,
    CITY_LAS_VEGAS,
    CITY_PHOENIX,
    CITY_SANTA_FE,
    CITY_OKLAHOMA,
    CITY_DALLAS,
    CITY_KANSAS,
    CITY_LITTLE_ROCK,
    CITY_SAINT_LOUIS,
    CITY_NASHVILLE,
    CITY_ATLANTA,
    CITY_QUANTITY,
    CITY_UNKNOWN
} City;

typedef struct Route_S
{
    City city1;
    City city2;
    Color color;
} Route;

const static Route k_routes[] =
{
  { .city1 = CITY_WANCOUVER,      .city2 = CITY_SEATTLE,        .color = COLOR_ANY   },
  { .city1 = CITY_WANCOUVER,      .city2 = CITY_SEATTLE,        .color = COLOR_ANY   },
  { .city1 = CITY_PORTLAND,       .city2 = CITY_SEATTLE,        .color = COLOR_ANY   },
  { .city1 = CITY_PORTLAND,       .city2 = CITY_SEATTLE,        .color = COLOR_ANY   },
  { .city1 = CITY_PORTLAND,       .city2 = CITY_SAN_FRANCISCO,  .color = COLOR_GREEN },
  { .city1 = CITY_PORTLAND,       .city2 = CITY_SAN_FRANCISCO,  .color = COLOR_ROSE  },
  { .city1 = CITY_LOS_ANGELOS,    .city2 = CITY_SAN_FRANCISCO,  .color = COLOR_ROSE  },
  { .city1 = CITY_LOS_ANGELOS,    .city2 = CITY_SAN_FRANCISCO,  .color = COLOR_YELLOW },
  { .city1 = CITY_LOS_ANGELOS,    .city2 = CITY_EL_PASO,        .color = COLOR_BLACK },
  { .city1 = CITY_HOUSTON,        .city2 = CITY_EL_PASO,        .color = COLOR_GREEN },
  { .city1 = CITY_HOUSTON,        .city2 = CITY_NEW_ORLEANS,    .color = COLOR_ANY },
  { .city1 = CITY_MIAMI,          .city2 = CITY_NEW_ORLEANS,    .color = COLOR_RED },
  { .city1 = CITY_MIAMI,          .city2 = CITY_CHARLESTON,     .color = COLOR_ROSE },
  { .city1 = CITY_RALIEGH,        .city2 = CITY_CHARLESTON,     .color = COLOR_ANY },
  { .city1 = CITY_RALIEGH,        .city2 = CITY_WASHINGTON,     .color = COLOR_ANY },
  { .city1 = CITY_RALIEGH,        .city2 = CITY_WASHINGTON,     .color = COLOR_ANY },
  { .city1 = CITY_NEW_YORK,       .city2 = CITY_WASHINGTON,     .color = COLOR_BLACK },
  { .city1 = CITY_NEW_YORK,       .city2 = CITY_WASHINGTON,     .color = COLOR_ORANGE },
  { .city1 = CITY_NEW_YORK,       .city2 = CITY_BOSTON,         .color = COLOR_YELLOW},
  { .city1 = CITY_NEW_YORK,       .city2 = CITY_BOSTON,         .color = COLOR_RED },
  { .city1 = CITY_MONTREAL,       .city2 = CITY_BOSTON,         .color = COLOR_ANY },
  { .city1 = CITY_MONTREAL,       .city2 = CITY_BOSTON,         .color = COLOR_ANY },
  { .city1 = CITY_MONTREAL,       .city2 = CITY_SAULT_ST_MARIE, .color = COLOR_BLACK },
  { .city1 = CITY_WINNIPEG,       .city2 = CITY_SAULT_ST_MARIE, .color = COLOR_ANY },
  { .city1 = CITY_WINNIPEG,       .city2 = CITY_CALGARY,        .color = COLOR_WHITE },
  { .city1 = CITY_WANCOUVER,      .city2 = CITY_CALGARY,        .color = COLOR_ANY },
  { .city1 = CITY_SEATTLE,        .city2 = CITY_CALGARY,        .color = COLOR_ANY },
  { .city1 = CITY_HELENA,         .city2 = CITY_CALGARY,        .color = COLOR_ANY },
  { .city1 = CITY_HELENA,         .city2 = CITY_WINNIPEG,       .color = COLOR_BLUE },
  { .city1 = CITY_DULUTH,         .city2 = CITY_WINNIPEG,       .color = COLOR_BLACK },
  { .city1 = CITY_DULUTH,         .city2 = CITY_SAULT_ST_MARIE, .color = COLOR_ANY },
  { .city1 = CITY_TORONTO,        .city2 = CITY_SAULT_ST_MARIE, .color = COLOR_ANY },
  { .city1 = CITY_TORONTO,        .city2 = CITY_MONTREAL,       .color = COLOR_ANY },
  { .city1 = CITY_BOSTON,         .city2 = CITY_MONTREAL,       .color = COLOR_BLUE },
  { .city1 = CITY_TORONTO,        .city2 = CITY_DULUTH,         .color = COLOR_ROSE },
  { .city1 = CITY_HELENA,         .city2 = CITY_DULUTH,         .color = COLOR_ORANGE },
  { .city1 = CITY_HELENA,         .city2 = CITY_SEATTLE,        .color = COLOR_YELLOW },
  { .city1 = CITY_PORTLAND,       .city2 = CITY_SALT_LAKE,      .color = COLOR_BLUE },
  { .city1 = CITY_HELENA,         .city2 = CITY_SALT_LAKE,      .color = COLOR_ROSE },
  { .city1 = CITY_HELENA,         .city2 = CITY_DENVER,         .color = COLOR_GREEN },
  { .city1 = CITY_HELENA,         .city2 = CITY_OMAHA,          .color = COLOR_RED },
  { .city1 = CITY_DULUTH,         .city2 = CITY_OMAHA,          .color = COLOR_ANY },
  { .city1 = CITY_DULUTH,         .city2 = CITY_OMAHA,          .color = COLOR_ANY },
  { .city1 = CITY_DULUTH,         .city2 = CITY_CHICAGO,        .color = COLOR_RED },
  { .city1 = CITY_TORONTO,        .city2 = CITY_CHICAGO,        .color = COLOR_WHITE },
  { .city1 = CITY_TORONTO,        .city2 = CITY_PITTSBURGH,     .color = COLOR_ANY },
  { .city1 = CITY_DENVER,         .city2 = CITY_OMAHA,          .color = COLOR_ROSE },
  { .city1 = CITY_KANSAS,         .city2 = CITY_OMAHA,          .color = COLOR_ANY },
  { .city1 = CITY_KANSAS,         .city2 = CITY_OMAHA,          .color = COLOR_ANY },
  { .city1 = CITY_CHICAGO,        .city2 = CITY_OMAHA,          .color = COLOR_BLUE },
  { .city1 = CITY_CHICAGO,        .city2 = CITY_SAINT_LOUIS,    .color = COLOR_GREEN },
  { .city1 = CITY_CHICAGO,        .city2 = CITY_SAINT_LOUIS,    .color = COLOR_WHITE },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_SAINT_LOUIS,    .color = COLOR_GREEN },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_NASHVILLE,      .color = COLOR_YELLOW },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_RALIEGH,        .color = COLOR_ANY },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_WASHINGTON,     .color = COLOR_ANY },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_CHICAGO,        .color = COLOR_ORANGE },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_CHICAGO,        .color = COLOR_BLACK },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_NEW_YORK,       .color = COLOR_WHITE },
  { .city1 = CITY_PITTSBURGH,     .city2 = CITY_NEW_YORK,       .color = COLOR_GREEN },
  { .city1 = CITY_RALIEGH,        .city2 = CITY_NASHVILLE,      .color = COLOR_BLACK },
  { .city1 = CITY_SAINT_LOUIS,    .city2 = CITY_NASHVILLE,      .color = COLOR_ANY },
  { .city1 = CITY_SAINT_LOUIS,    .city2 = CITY_KANSAS,         .color = COLOR_BLUE },
  { .city1 = CITY_SAINT_LOUIS,    .city2 = CITY_KANSAS,         .color = COLOR_ROSE },
  { .city1 = CITY_DENVER,         .city2 = CITY_KANSAS,         .color = COLOR_ORANGE },
  { .city1 = CITY_DENVER,         .city2 = CITY_KANSAS,         .color = COLOR_BLACK },
  { .city1 = CITY_DENVER,         .city2 = CITY_SALT_LAKE,      .color = COLOR_RED },
  { .city1 = CITY_DENVER,         .city2 = CITY_SALT_LAKE,      .color = COLOR_YELLOW },
  { .city1 = CITY_SAN_FRANCISCO,  .city2 = CITY_SALT_LAKE,      .color = COLOR_ORANGE },
  { .city1 = CITY_SAN_FRANCISCO,  .city2 = CITY_SALT_LAKE,      .color = COLOR_WHITE },
  { .city1 = CITY_LAS_VEGAS,      .city2 = CITY_SALT_LAKE,      .color = COLOR_ORANGE },
  { .city1 = CITY_LAS_VEGAS,      .city2 = CITY_LOS_ANGELOS,    .color = COLOR_ANY },
  { .city1 = CITY_DENVER,         .city2 = CITY_PHOENIX,        .color = COLOR_WHITE },
  { .city1 = CITY_DENVER,         .city2 = CITY_SANTA_FE,       .color = COLOR_ANY },
  { .city1 = CITY_DENVER,         .city2 = CITY_OKLAHOMA,       .color = COLOR_RED },
  { .city1 = CITY_KANSAS,         .city2 = CITY_OKLAHOMA,       .color = COLOR_ANY },
  { .city1 = CITY_KANSAS,         .city2 = CITY_OKLAHOMA,       .color = COLOR_ANY },
  { .city1 = CITY_SAINT_LOUIS,    .city2 = CITY_LITTLE_ROCK,    .color = COLOR_ANY },
  { .city1 = CITY_SAINT_LOUIS,    .city2 = CITY_LITTLE_ROCK,    .color = COLOR_ANY },
  { .city1 = CITY_ATLANTA,        .city2 = CITY_RALIEGH,        .color = COLOR_ANY },
  { .city1 = CITY_ATLANTA,        .city2 = CITY_RALIEGH,        .color = COLOR_ANY },
  { .city1 = CITY_ATLANTA,        .city2 = CITY_CHARLESTON,     .color = COLOR_ANY },
  { .city1 = CITY_LITTLE_ROCK,    .city2 = CITY_NASHVILLE,      .color = COLOR_WHITE },
  { .city1 = CITY_LITTLE_ROCK,    .city2 = CITY_OKLAHOMA,       .color = COLOR_ANY },
  { .city1 = CITY_SANTA_FE,       .city2 = CITY_OKLAHOMA,       .color = COLOR_BLUE },
  { .city1 = CITY_SANTA_FE,       .city2 = CITY_PHOENIX,        .color = COLOR_ANY },
  { .city1 = CITY_LOS_ANGELOS,    .city2 = CITY_PHOENIX,        .color = COLOR_ANY },
  { .city1 = CITY_EL_PASO,        .city2 = CITY_PHOENIX,        .color = COLOR_ANY },
  { .city1 = CITY_EL_PASO,        .city2 = CITY_SANTA_FE,       .color = COLOR_ANY },
  { .city1 = CITY_EL_PASO,        .city2 = CITY_OKLAHOMA,       .color = COLOR_YELLOW },
  { .city1 = CITY_EL_PASO,        .city2 = CITY_DALLAS,         .color = COLOR_RED },
  { .city1 = CITY_OKLAHOMA,       .city2 = CITY_DALLAS,         .color = COLOR_ANY },
  { .city1 = CITY_OKLAHOMA,       .city2 = CITY_DALLAS,         .color = COLOR_ANY },
  { .city1 = CITY_LITTLE_ROCK,    .city2 = CITY_DALLAS,         .color = COLOR_ANY },
  { .city1 = CITY_HOUSTON,        .city2 = CITY_DALLAS,         .color = COLOR_ANY },
  { .city1 = CITY_HOUSTON,        .city2 = CITY_DALLAS,         .color = COLOR_ANY },
  { .city1 = CITY_LITTLE_ROCK,    .city2 = CITY_NEW_ORLEANS,    .color = COLOR_GREEN },
  { .city1 = CITY_ATLANTA,        .city2 = CITY_NEW_ORLEANS,    .color = COLOR_YELLOW },
  { .city1 = CITY_ATLANTA,        .city2 = CITY_NEW_ORLEANS,    .color = COLOR_ORANGE },
  { .city1 = CITY_ATLANTA,        .city2 = CITY_MIAMI,          .color = COLOR_BLUE },
};


typedef struct
{
    City city1;
    City city2;
    size_t points;
} Route_Card;

const static size_t k_route_cards = 30;
const static Route_Card route_cards[] =
{
    { .city1 = CITY_SEATTLE,        .city2 = CITY_LOS_ANGELOS,  .points = 9  },
    { .city1 = CITY_CHICAGO,        .city2 = CITY_LOS_ANGELOS,  .points = 16 },
    { .city1 = CITY_PORTLAND,       .city2 = CITY_NASHVILLE,    .points = 17 },
    { .city1 = CITY_WINNIPEG,       .city2 = CITY_LITTLE_ROCK,  .points = 11 },
    { .city1 = CITY_DULUTH,         .city2 = CITY_HOUSTON,      .points = 8  },
    { .city1 = CITY_SAULT_ST_MARIE, .city2 = CITY_OKLAHOMA,     .points = 9  },
    { .city1 = CITY_NEW_YORK,       .city2 = CITY_ATLANTA,      .points = 6  },
    { .city1 = CITY_WANCOUVER,      .city2 = CITY_SANTA_FE,     .points = 13 },
    { .city1 = CITY_NEW_YORK,       .city2 = CITY_LOS_ANGELOS,  .points = 21 },
    { .city1 = CITY_DENVER,         .city2 = CITY_PITTSBURGH,   .points = 11 },
    { .city1 = CITY_TORONTO,        .city2 = CITY_MIAMI,        .points = 10 },
    { .city1 = CITY_SAN_FRANCISCO,  .city2 = CITY_ATLANTA,      .points = 17 },
    { .city1 = CITY_CALGARY,        .city2 = CITY_PHOENIX,      .points = 13 },
    { .city1 = CITY_HELENA,         .city2 = CITY_LOS_ANGELOS,  .points = 8  },
    { .city1 = CITY_LOS_ANGELOS,    .city2 = CITY_MIAMI,        .points = 20 },
    { .city1 = CITY_WINNIPEG,       .city2 = CITY_HOUSTON,      .points = 12 },
    { .city1 = CITY_CALGARY,        .city2 = CITY_SALT_LAKE,    .points = 7  },
    { .city1 = CITY_PORTLAND,       .city2 = CITY_PHOENIX,      .points = 11 },
    { .city1 = CITY_BOSTON,         .city2 = CITY_MIAMI,        .points = 12 },
    { .city1 = CITY_CHICAGO,        .city2 = CITY_NEW_ORLEANS,  .points = 7  },
    { .city1 = CITY_MONTREAL,       .city2 = CITY_ATLANTA,      .points = 9  },
    { .city1 = CITY_MONTREAL,       .city2 = CITY_NEW_ORLEANS,  .points = 13 },
    { .city1 = CITY_SAULT_ST_MARIE, .city2 = CITY_NASHVILLE,    .points = 8  },
    { .city1 = CITY_HOUSTON,        .city2 = CITY_KANSAS,       .points = 5  },
    { .city1 = CITY_DALLAS,         .city2 = CITY_NEW_YORK,     .points = 11 },
    { .city1 = CITY_SEATTLE,        .city2 = CITY_NEW_YORK,     .points = 22 },
    { .city1 = CITY_EL_PASO,        .city2 = CITY_DENVER,       .points = 4  },
    { .city1 = CITY_CHICAGO,        .city2 = CITY_SANTA_FE,     .points = 9  },
    { .city1 = CITY_WANCOUVER,      .city2 = CITY_MONTREAL,     .points = 20 },
    { .city1 = CITY_DULUTH,         .city2 = CITY_EL_PASO,      .points = 10 },
};


typedef struct Route_Deck_S
{
    Route_Card *cards;
    size_t q_cards;
} Route_Deck;

void
route_deck_init(Route_Deck *deck);

void
route_deck_draw_card(Route_Deck *deck, Route route);

#endif /* __ROUTES_H__ */