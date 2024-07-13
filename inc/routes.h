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
    CITY_QUANTITY
} City;

typedef struct Route_S
{
    City city1;
    City city2;
    Color color;
} Route;

const static Route k_routes[] =
{
  { .city1 = CITY_EL_PASO, .city2 = CITY_HOUSTON, .color = COLOR_GREEN }  
};


typedef struct Route_Deck_S
{
    size_t cards;
} Route_Deck;

#endif /* __ROUTES_H__ */