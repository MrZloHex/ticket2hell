#include "parser.h"

Command_OPT
parse(char *s)
{
    Command_OPT res = { .success = true };
    char* tocens[7];
    size_t i = 0;
    char* tocen = strtok(s, " ");
    while (tocen != NULL)
    {
        if(i == 7)
        { break; }
        if(strlen(tocen) != 0)
        {
            tocens[i] = tocen;
            ++i;
        }
        tocen = strtok(NULL, " ");
    }
    if(i <= 1)
    {
        res.success = false;
        return res;
    }
    ACTION_OPT action = str2action(tocens[0]);
    if(action.success == true)
    {
        if(action.value == ACT_DRAW_TRAIN)
        {
            if(i != 2)
            {
                res.success = false;
                return res;
            }
            res.value.params.act.type = ACT_DRAW_TRAIN;
            
            Color_OPT color = str2color(tocens[1]);
            if(color.success == true)
            { res.value.params.act.params.color = color.value; }
            else
            {
                res.success = false;
                return res;
            }
            return res;
        }
        else if(action.value == ACT_DRAW_TICKET)
        {
            size_t j = 1; 
            res.value.params.act.type = ACT_DRAW_TICKET;
            CITY_OPT city = find_city(tocens, &j, &i);
            if(city.success == true)
            { res.value.params.act.params.route.city1 = city.value; }
            else 
            {
                res.success = false;
                return res;
            }
            city = find_city(tocens, &j, &i);
            if(city.success == true)
            { res.value.params.act.params.route.city2 = city.value; }
            else 
            {
                res.success = false;
                return res;
            }
            return res;
        }
        else if(action.value == ACT_CLAIN_ROUTE)
        {
            size_t j = 1; 
            res.value.params.act.type = ACT_CLAIN_ROUTE;
            CITY_OPT city = find_city(tocens, &j, &i);
            if(city.success == true)
            { res.value.params.act.params.route.city1 = city.value; }
            else 
            {
                res.success = false;
                return res;
            }
            city = find_city(tocens, &j, &i);
            if(city.success == true)
            { res.value.params.act.params.route.city2 = city.value; }
            else 
            {
                res.success = false;
                return res;
            }
            Color_OPT color = str2color(tocens[j]);
            if(color.success == true)
            { res.value.params.act.params.color = color.value; }
            else
            {
                res.success = false;
                return res;
            }
            return res;

        }
        res.success = false;
        return res;
    }
    char* cmd_str = concat(tocens[0], tocens[1], ' ');
    CMD_OPT cmd = str2cmd(cmd_str);
    if(cmd.success == true && i == 3)
    {
        res.value.type = cmd.value;
        res.value.params.name = tocens[2];
    }
    res.success = false;
    return res;
}



Color_OPT
str2color(const char *str)
{
    Color_OPT opt = { .success = true };
    for (size_t i = 0; i < color_quantity; ++i)
    {
        if (strcmp(str, conversion_color[i].str) == 0)
        {
            opt.value = conversion_color[i].val; 
            return opt;   
        }
    }
    opt.success = false;
    return opt;
}

CMD_OPT
str2cmd(const char *str)
{
    CMD_OPT opt = { .success = true };
    for (size_t i = 0; i < cmd_quantity; ++i)
    {
        if (strcmp(str, conversion_cmd[i].str) == 0)
        {
            opt.value = conversion_cmd[i].val; 
            return opt;   
        }
    }
    opt.success = false;
    return opt;
}

ACTION_OPT
str2action(const char *str)
{
    ACTION_OPT opt = { .success = true };
    for (size_t i = 0; i < actions_quantity; ++i)
    {
        if (strcmp(str, conversion_actions[i].str) == 0)
        {
            opt.value = conversion_actions[i].val; 
            return opt;   
        }
    }
    opt.success = false;
    return opt;
}

CITY_OPT
str2city(const char *str)
{
    CITY_OPT opt = { .success = true };
    for (size_t i = 0; i < city_quantity;  ++i)
    {
        if (strcmp(str, conversion_city[i].str) == 0)
        {
            opt.value = conversion_city[i].val; 
            return opt;   
        }
    }
    opt.success = false;
    return opt;
}

char*
concat(const char *s1, const char *s2, const char c)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 2);
    memcpy(result, s1, len1);
    result[len1] = c;
    memcpy(result + len1 + 1, s2, len2 + 1);
    return result;
}

CITY_OPT
find_city(char** arr, size_t* i, size_t* size)
{
    size_t j = 0;
    CITY_OPT res;
    size_t position = *i;
    size_t size_arr = *size;
    char* str = arr[position];

    while (size_arr - position > 1 && j < 3)
    {
        res = str2city(str);
        if(res.success == true)
        {
            *i = position + 1;
            return res;
        }
        ++j;
        ++position;
        char* temp = concat(str, arr[position], '_');
        str = temp;
        temp = NULL;
    }
    res = str2city(str);
    ++position;

    return res;    
}