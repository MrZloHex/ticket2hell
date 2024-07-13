#include "util.h"
#include <unistd.h>
#include <termios.h>

void
cerror(const char * restrict fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\033[0;31mERROR\033[0m: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);

    exit(1);
}

int
wait_for_input()
{
    int ch;
    struct termios oldt, newt;
  
    tcgetattr ( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );
  
    return ch;
}