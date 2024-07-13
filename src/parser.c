#include "parser.h"
#include <string.h>



CMD_PARSED
parser_parse(Parser *parser, char *s)
{
    CMD_PARSED res;
    char *pch = strtok(s, " ");
    
    while (pch != NULL)                        
    {
        
        pch = strtok (NULL, " ");
    }
}

DEFINE_OPTION(Color, Color_OPT);
Color_OPT
str2Color (const char *str)
{
    Color_OPT opt = { .success = true };
     int j;
     for (j = 0;  j < sizeof (conversion_color) / sizeof (conversion_color[0]);  ++j)
     {
         if (!strcmp (str, conversion_color[j].str))
             opt.value = conversion_color[j].val; 
             return opt;   
     }

     opt.success = false;
     return opt;
}

CMD
str2CMD (const char *str)
{
     int j;
     for (j = 0;  j < sizeof (conversion_cmd) / sizeof (conversion_cmd[0]);  ++j)
     {
         if (!strcmp (str, conversion_cmd[j].str))
             return conversion_cmd[j].val;    
     }
     return -1;
}

City
str2City (const char *str)
{
     int j;
     for (j = 0;  j < sizeof (conversion_city) / sizeof (conversion_city[0]);  ++j)
     {
         if (!strcmp (str, conversion_city[j].str))
             return conversion_city[j].val;    
     }
     error_message ("no such string");
}