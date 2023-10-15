#ifndef __TEST_H__
#define __TEST_H__

#include "uni.h"

/* Enum and Structure */
typedef struct {
    int x;
    int y;
} Point;


/* Functions */
void test_main();

SCODE test_basic();
SCODE test_point();
SCODE test_copy();

#endif // __TEST_H__
