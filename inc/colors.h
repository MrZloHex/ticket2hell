#ifndef __COLORS_H__
#define __COLORS_H__

#include "stdint.h"

const static char *k_colors_s[] =
{
    "ROSE", "WHITE", "BLUE", "YELLOW",
    "ORANGE", "BLACK", "RED", "GREEN",
    "QQQQQ", "ANY", "UNKNOWN"
};

const static uint8_t k_colors_esc[] =
{
    200, 255, 21, 226, 202, 0, 196, 82, 52, 235, 103
};

typedef enum Color_E
{
    COLOR_ROSE,
    COLOR_WHITE,
    COLOR_BLUE,
    COLOR_YELLOW,
    COLOR_ORANGE,
    COLOR_BLACK,
    COLOR_RED,
    COLOR_GREEN,
    COLORS_QUANTITY,
    COLOR_ANY,
    COLOR_UNKNOWN       // FOR TRAIN CARDS DRAWED IN CLOSED
} Color;

#endif /* __COLORS_H__ */