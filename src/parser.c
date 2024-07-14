#include "parser.h"
#include <string.h>
Parser
f_Parset(char *s)
{
    Parser res;
    char *pch = strtok (s," ");
    
    while (pch != NULL)                        
    {
        res.value.type = str2CMD(pch).value;
        pch = strtok (NULL, " ");
        res.value.params.name = pch;
        printf("\n\nPARSER   --  %s\n\n", pch  );
        return res;     
    }else if(str2Actions(pch).success)
    {
        res.value.params.act.type = str2Actions(pch).value;
        if(res.value.params.act.type == ACT_DRAW_TRAIN)
        {
            pch = strtok (NULL, " ");
            if(str2Color(pch).success)
            { res.value.params.act.params.color = str2Color(pch).value; }
        }else if(res.value.params.act.type == ACT_DRAW_TICKET)
        {
            pch = strtok (NULL, " ");
            if(str2City(pch).success)
            { res.value.params.act.params.route.city1 = str2City(pch).value; }
            
            pch = strtok (NULL, " ");
            if(str2City(pch).success)
            { res.value.params.act.params.route.city2 = str2City(pch).value; }
            return res;
        }else if(res.value.params.act.type == ACT_CLAIN_ROUTE)
        {
            pch = strtok (NULL, " ");
            if(str2City(pch).success)
            { res.value.params.act.params.route.city1 = str2City(pch).value; }
            
            pch = strtok (NULL, " ");
            if(str2City(pch).success)
            { res.value.params.act.params.route.city2 = str2City(pch).value; }

            pch = strtok (NULL, " ");
            if(str2Color(pch).success)
            { res.value.params.act.params.color = str2Color(pch).value; }
            return res;   
        }

    }
    res.success = false;
    return res;    
}

Color_OPT
str2Color (const char *str)
{
    Color_OPT opt = { .success = true };
     int j;
     for (j = 0;  j < sizeof (conversion_color) / sizeof (conversion_color[0]);  ++j)
     {
         if (!strcmp (str, conversion_color[j].str))
             {
                opt.value = conversion_color[j].val; 
                return opt;   
             }
     }

     opt.success = false;
     return opt;
}

CMD_OPT
str2CMD (const char *str)
{
    CMD_OPT opt = { .success = true };
     int j;
     for (j = 0;  j < sizeof (conversion_cmd) / sizeof (conversion_cmd[0]);  ++j)
     {
         if (!strcmp (str, conversion_cmd[j].str))
             {
                opt.value = conversion_cmd[j].val; 
                return opt;   
             }
     }

     opt.success = false;
     return opt;
}

ACTION_OPT
str2Actions (const char *str)
{
    ACTION_OPT opt = { .success = true };
     int j;
     for (j = 0;  j < sizeof (conversion_actions) / sizeof (conversion_actions[0]);  ++j)
     {
         if (!strcmp (str, conversion_actions[j].str))
             {
                opt.value = conversion_actions[j].val; 
                return opt;   
             }
     }

     opt.success = false;
     return opt;
}

CITY_OPT
str2City (const char *str)
{
    CITY_OPT opt = { .success = true };
     int j;
     for (j = 0;  j < sizeof (conversion_city) / sizeof (conversion_city[0]);  ++j)
     {
         if (!strcmp (str, conversion_city[j].str))
             {
                opt.value = conversion_city[j].val; 
                return opt;   
             }
     }

     opt.success = false;
     return opt;
}