#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void
cerror(const char * restrict fmt, ...);

int
wait_for_input();

#endif /* __UTIL_H__ */