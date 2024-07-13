#ifndef __PARSER_H__
#define __PARSER_H__

#include "colors.h"
#include "routes.h"
#include "result.h"


typedef struct CMD_S
{
    /* data */
}CMD;

typedef struct Parser_S
{
    CMD cmd;
    Color color;
    City city[2];
} CMD_PARSED;

const static struct {
    CMD      val;
    const char *str;
} conversion_cmd [] = {
    
};

const static struct {
    Color      val;
    const char *str;
} conversion_color [] = {
    {COLOR_ROSE, "ROSE"},
    {COLOR_WHITE, "WHITE"},
    {COLOR_BLUE, "BLUE"},
    {COLOR_YELLOW, "YELLOW"},
    {COLOR_ORANGE, "ORANGE"},
    {COLOR_BLACK, "BLACK"},
    {COLOR_RED, "RED"},
    {COLOR_GREEN, "GREEN"},
    {COLORS_QUANTITY, "QUANTITY"},
    {COLOR_ANY, "ANY"},
};

const static struct {
    City      val;
    const char *str;
} conversion_city [] = {
    {CITY_WANCOUVER, "ANY"},
    {CITY_SEATTLE, "CITY_SEATTLE"},
    {CITY_PORTLAND, "CITY_PORTLAND"},
    {CITY_SAN_FRANCISCO, "CITY_SAN_FRANCISCO"},
    {CITY_LOS_ANGELOS, "CITY_LOS_ANGELOS"},
    {CITY_EL_PASO, "CITY_EL_PASO"},
    {CITY_HOUSTON, "CITY_HOUSTON"},
    {CITY_NEW_ORLEANS, "CITY_NEW_ORLEANS"},
    {CITY_MIAMI, "CITY_MIAMI"},
    {CITY_CHARLESTON, "CITY_CHARLESTON"},
    {CITY_RALIEGH, "CITY_RALIEGH"},
    {CITY_WASHINGTON, "CITY_WASHINGTON"},
    {CITY_NEW_YORK, "CITY_NEW_YORK"},
    {CITY_BOSTON, "CITY_BOSTON"},
    {CITY_MONTREAL, "CITY_MONTREAL"},
    {CITY_SAULT_ST_MARIE, "CITY_SAULT_ST_MARIE"},
    {CITY_WINNIPEG, "CITY_WINNIPEG"},
    {CITY_CALGARY, "CITY_CALGARY"},
    {CITY_HELENA, "CITY_HELENA"},
    {CITY_DULUTH, "CITY_DULUTH"},
    {CITY_TORONTO, "CITY_TORONTO"},
    {CITY_PITTSBURGH, "CITY_PITTSBURGH"},
    {CITY_CHICAGO, "CITY_CHICAGO"},
    {CITY_OMAHA, "CITY_OMAHA"},
    {CITY_DENVER, "CITY_DENVER"},
    {CITY_SALT_LAKE, "CITY_SALT_LAKE"},
    {CITY_LAS_VEGAS, "CITY_LAS_VEGAS"},
    {CITY_PHOENIX, "CITY_PHOENIX"},
    {CITY_SANTA_FE, "CITY_SANTA_FE"},
    {CITY_OKLAHOMA, "CITY_OKLAHOMA"},
    {CITY_DALLAS, "CITY_DALLAS"},
    {CITY_KANSAS, "CITY_KANSAS"},
    {CITY_LITTLE_ROCK, "CITY_LITTLE_ROCK"},
    {CITY_SAINT_LOUIS, "CITY_SAINT_LOUIS"},
    {CITY_NASHVILLE, "CITY_NASHVILLE"},
    {CITY_ATLANTA, "CITY_ATLANTA"},
    {CITY_QUANTITY, "CITY_QUANTITY"},

};


typedef struct Parser_S
{

} Parser;

void
parser_init(Parser *parser);

CMD_PARSED
parser_parse(Parser *parser, char *str);

void
parser_deinit(Parser *parser);


#endif /* __PARSER_H__ */