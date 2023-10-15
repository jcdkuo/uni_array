#ifndef __UTIL_H__
#define __UTIL_H__

#include "uni.h"

/* Definition */
#define DEFAULT_VALID_TIME "1970-01-01T00:00:00.000Z"

/* Enum and Structure */

/* Functions */
time_t current_unix_timestamp();
time_t convert_to_unix_timestamp(const char *time_str);

char*   convert_unix_to_format(time_t timestamp);
char*   convert_unix_to_24hour(time_t timestamp);
char*   convert_unix_to_rfc3339(time_t timestamp);

int     unix_timestamp_to_weekday(time_t timestamp);

void    clear_struct(void *struct_ptr, size_t struct_size);
void    print_time_diff(clock_t start, const char *message);

#endif // __UTIL_H__
