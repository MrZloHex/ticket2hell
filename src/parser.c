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
        if (i == 7)
        { break; }
        if (strlen(tocen) != 0)
        {
            tocens[i] = malloc(strlen(tocen) + 1);
            memcpy(tocens[i], tocen, strlen(tocen));
            ++i;
        }
        tocen = strtok(NULL, " ");
    }
    if (i <= 1)
    {
        for(int t = 0; t < i; ++t)
        { free(tocens[t]); }
        res.success = false;
        return res;
    }
    ACTION_OPT action = str2action(tocens[0]);
    if (action.success == true)
    {
        if (action.value == ACT_DRAW_TRAIN)
        {
            if (i != 2)
            {
                for(int t = 0; t < i; ++t)
                { free(tocens[t]); }
                res.success = false;
                return res;
            }
            res.value.params.act.type = ACT_DRAW_TRAIN;
            
            Color_OPT color = str2color(tocens[1]);
            if (color.success == true)
            { res.value.params.act.params.color = color.value; }
            else
            {
                for(int t = 0; t < i; ++t)
                { free(tocens[t]); }
                res.success = false;
                return res;
            }
            for(int t = 0; t < i; ++t)
            { free(tocens[t]); }
                
            return res;
        }
        else if (action.value == ACT_DRAW_TICKET)
        {
            size_t j = 1; 
            res.value.params.act.type = ACT_DRAW_TICKET;
            CITY_OPT city = find_city(tocens, &j, &i);
            if (city.success == true)
            { res.value.params.act.params.route.city1 = city.value; }
            else 
            {
                for(int t = 0; t < i; ++t)
                { free(tocens[t]); }
                res.success = false;
                return res;
            }
            city = find_city(tocens, &j, &i);
            if (city.success == true)
            { res.value.params.act.params.route.city2 = city.value; }
            else 
            {
                for(int t = 0; t < i; ++t)
                { free(tocens[t]); }
                res.success = false;
                return res;
            }
            for(int t = 0; t < i; ++t)
            { free(tocens[t]); }
                
            return res;
        }
        else if (action.value == ACT_CLAIN_ROUTE)
        {
            size_t j = 1; 
            res.value.params.act.type = ACT_CLAIN_ROUTE;
            CITY_OPT city = find_city(tocens, &j, &i);
            if(city.success == true)
            { res.value.params.act.params.route.city1 = city.value; }
            else 
            {
                for(int t = 0; t < i; ++t)
                { free(tocens[t]); }
                
                res.success = false;
                return res;
            }
            city = find_city(tocens, &j, &i);
            if (city.success == true)
            { res.value.params.act.params.route.city2 = city.value; }
            else 
            {
                for(int t = 0; t < i; ++t)
                { free(tocens[t]); }
                res.success = false;
                return res;
            }
            Color_OPT color = str2color(tocens[j]);
            if (color.success == true)
            { res.value.params.act.params.color = color.value; }
            else
            {
                for(int t = 0; t < i; ++t)
                { free(tocens[t]); }
                res.success = false;
                return res;
            }
            for(int t = 0; t < i; ++t)
            { free(tocens[t]); }  
            return res;

        }
        for(int t = 0; t < i; ++t)
        { free(tocens[t]); }
        res.success = false;
        return res;
    }
    //char* cmd_str = concat(tocens[0], tocens[1], ' ');
    char* cmd_str = strcat(tocens[0], " ");
    cmd_str = strcat(cmd_str, tocens[0]);
    
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
        str = strcat(str, arr[position]);
    }
    res = str2city(str);
    ++position;

    return res;    
}
