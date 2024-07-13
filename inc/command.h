#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "actions.h"

typedef enum
{
    CMD_ADD_PLAYER,
    CMD_SET_FIRST,
    CMD_ACTION,
} CMD_Type;

typedef union
{
    char *name;
    Action act;
} CMD_Params;

typedef struct Command_S
{
    CMD_Type type;
    CMD_Params params;
} Command;

#endif /* __COMMAND_H__ */