#ifndef __TEST_H__
#define __TEST_H__

#include "uni.h"

/* Definiton */
#define WORKER_NAME_LEN             64
#define WORKER_ALIAS_LEN            64
#define WORKER_STATUS_LEN           24
#define WORKER_TYPE_LEN             8

#define MAX_WORKER_RECORD           100

/* Enum and Structure */
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int64_t     revision;

    char        worker_id[UUID_LEN];
    char        worker_name[WORKER_NAME_LEN];
    char        worker_alias[WORKER_ALIAS_LEN];
    char        worker_status[WORKER_STATUS_LEN];
    char        worker_type[WORKER_TYPE_LEN];
    time_t      worker_lifecycle_starttime;
    time_t      worker_lifecycle_endtime;

} worker_t;

/* Functions */
void test_main();

SCODE test_basic();
SCODE test_point();
SCODE test_copy();
SCODE test_worker();

#endif // __TEST_H__
