#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include "colors.h"
#include "routes.h"

typedef enum Action_Type_E
{
    ACT_DRAW_TRAIN,
    ACT_DRAW_TICKET,
    ACT_CLAIM_ROUTE,
    ACT_UPDATE_POOL
} Action_Type;

typedef union
{
    Color color;
    Route route;
} Action_Params;

typedef struct Action_S
{
    Action_Type type;
    Action_Params params;
} Action;



#endif /* __ACTIONS_H__ */