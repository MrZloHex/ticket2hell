#include "stdio.h"
#include "parser.h"
#include "command.h"

int
main(void)
{
    printf("TICKET TO HELL!!!!\n");
   
    char str[] = "ticket Pittsburgh New York";
    Command_OPT opt = parse(str);
    printf("\n\n name   -    %d\n\n", opt.value.params.act.params.route.city1);
        printf("\n\n name   -    %d\n\n", opt.value.params.act.params.route.city2);

    return 0;
}