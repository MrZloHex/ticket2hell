#include "stdio.h"
#include "parser.h"
#include "command.h"

int
main(void)
{
    printf("TICKET TO HELL!!!!\n");
   
    char str[] = "add player alex";
    Command_OPT opt = parse(str);
    printf("\n\n name   -    %s\n\n", opt.value.params.name);
    return 0;
}