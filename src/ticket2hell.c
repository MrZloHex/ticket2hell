#include "stdio.h"
#include "parser.h"
#include "command.h"

int
main(void)
{
    printf("TICKET TO HELL!!!!\n");
   
    char str[] = "CMD_ADD_PLAYER alex";
    Command_OPT opt = parse(str);
    
    return 0;
}