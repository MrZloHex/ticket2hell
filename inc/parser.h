#ifndef __PARSER_H__
#define __PARSER_H__


#include <string.h>

#include "colors.h"
#include "routes.h"
#include "result.h"
#include "command.h"
#include "actions.h"



const static struct {
    CMD_Type    val;
    const char *str;
} conversion_cmd [] = {
    { CMD_ADD_PLAYER, "add player" },
    { CMD_SET_FIRST,  "set first"  },
};
const static size_t cmd_quantity = sizeof(conversion_cmd) / sizeof(conversion_cmd[0]);

const static struct {
    Action_Type val;
    const char *str;
} conversion_actions [] = {
    { ACT_DRAW_TRAIN,  "train"  },
    { ACT_DRAW_TICKET, "ticket" },
    { ACT_CLAIN_ROUTE, "claim"  },
};
const static size_t actions_quantity = sizeof(conversion_actions) / sizeof(conversion_actions[0]);

const static struct {
    Color      val;
    const char *str;
} conversion_color [] = {
    { COLOR_ROSE,   "rose"    },
    { COLOR_WHITE,  "white"   },
    { COLOR_BLUE,   "vlue"    },
    { COLOR_YELLOW, "yellow"  },
    { COLOR_ORANGE, "ORANGE"  },
    { COLOR_BLACK,  "BLACK"   },
    { COLOR_RED,    "RED"     },
    { COLOR_GREEN,  "GREEN"   },
    { COLOR_ANY,    "ANY"     },
};
const static size_t color_quantity = sizeof(conversion_color) / sizeof(conversion_color[0]);

const static struct {
    City      val;
    const char *str;
} conversion_city [] = {
    { CITY_SEATTLE,        "Seattle"        },
    { CITY_PORTLAND,       "Portland"       },
    { CITY_SAN_FRANCISCO,  "SanFrancisco"   },
    { CITY_LOS_ANGELOS,    "LosAngelos"     },
    { CITY_EL_PASO,        "ElPaso"         },
    { CITY_HOUSTON,        "Houston"        },
    { CITY_NEW_ORLEANS,    "NewOrleans"     },
    { CITY_MIAMI,          "Miani"          },
    { CITY_CHARLESTON,     "Charleston"     },
    { CITY_RALIEGH,        "Raliegh"        },
    { CITY_WASHINGTON,     "Washington"     },
    { CITY_NEW_YORK,       "NewYork"        },
    { CITY_BOSTON,         "Boston"         },
    { CITY_MONTREAL,       "Montreal"       },
    { CITY_SAULT_ST_MARIE, "SaultStMarie"   },
    { CITY_WINNIPEG,       "Winnipeg"       },
    { CITY_CALGARY,        "Calgary"        },
    { CITY_HELENA,         "Helena"         },
    { CITY_DULUTH,         "Duluth"         },
    { CITY_TORONTO,        "Toronto"        },
    { CITY_PITTSBURGH,     "Pittsburgh"     },
    { CITY_CHICAGO,        "Chicago"        },
    { CITY_OMAHA,          "Omaha"          },
    { CITY_DENVER,         "Denver"         },
    { CITY_SALT_LAKE,      "SaltLake"       },
    { CITY_LAS_VEGAS,      "LasVegas"       },
    { CITY_PHOENIX,        "Phoenix"        },
    { CITY_SANTA_FE,       "SantaFe"        },
    { CITY_OKLAHOMA,       "Oklahoma"       },
    { CITY_DALLAS,         "Dallas"         },
    { CITY_KANSAS,         "Kansas"         },
    { CITY_LITTLE_ROCK,    "LittleRock"     },
    { CITY_SAINT_LOUIS,    "SaintLouis"     },
    { CITY_NASHVILLE,      "Nashville"      },
    { CITY_ATLANTA,        "Aylanta"        },
    { CITY_QUANTITY,       "Quantity"       },

};
const static size_t city_quantity = sizeof(conversion_city) / sizeof(conversion_city[0]);

DEFINE_OPTION(Command, Command_OPT);
DEFINE_OPTION(CMD_Type, CMD_OPT);
DEFINE_OPTION(Color, Color_OPT);
DEFINE_OPTION(Action_Type, ACTION_OPT);
DEFINE_OPTION(City, CITY_OPT);

Command_OPT
parse(char* s);

Color_OPT
str2color(const char *str);


CMD_OPT
str2cmd(const char *str);

ACTION_OPT
str2action(const char *str);

CITY_OPT
str2city(const char *str);

char*
concat(const char *s1, const char *s2, const char c);

CITY_OPT
find_city(char** arr, size_t* i, size_t* size);
#endif  /* __PARSER_H__ */ 