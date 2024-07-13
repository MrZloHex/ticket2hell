#ifndef __RESULT_H__
#define __RESULT_H__

#include <stdbool.h>

#define DEFINE_RESULT(T, E, NAME) \
typedef struct { \
  bool success; \
  union { \
    T result; \
    E error; \
  }; \
} NAME;

#define DEFINE_OPTION(T, NAME) \
typedef struct { \
  bool success; \
  T value; \
} NAME;

#endif /* __RESULT_H__ */

