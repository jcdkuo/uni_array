#include "uni.h"

void clear_struct(void *struct_ptr, size_t struct_size) {
    memset(struct_ptr, 0, struct_size);
}

time_t current_unix_timestamp() {
    time_t t;
    time(&t);
    return t;
}

time_t convert_to_unix_timestamp(const char *time_str) {
    struct tm tm = {0};

    sscanf(time_str, "%d-%d-%dT%d:%d:%d.%*3sZ",
           &tm.tm_year, &tm.tm_mon, &tm.tm_mday, 
           &tm.tm_hour, &tm.tm_min, &tm.tm_sec);

    tm.tm_year -= 1900;
    tm.tm_mon -= 1;

    time_t unix_time = mktime(&tm);

    return unix_time;
}

char* convert_unix_to_format(time_t timestamp) {
    struct tm* timeinfo;
    timeinfo = gmtime(&timestamp);

    static char format[21];
    strftime(format, 21, "%Y-%m-%d %H:%M:%S", timeinfo);

    return format;
}

char* convert_unix_to_24hour(time_t timestamp) {
    static char buffer[9];
    struct tm *tm_info = localtime(&timestamp);
    strftime(buffer, 9, "%H:%M:%S", tm_info);

    return buffer;
}

char* convert_unix_to_rfc3339(time_t timestamp) {
    struct tm* timeinfo;
    timeinfo = gmtime(&timestamp);

    static char rfc3339[21];
    strftime(rfc3339, 21, "%Y-%m-%dT%H:%M:%SZ", timeinfo);

    return rfc3339;
}

int unix_timestamp_to_weekday(time_t timestamp) {
    struct tm *tm_info;
    time_t t = timestamp;
    tm_info = localtime(&t);

    int weekday = tm_info->tm_wday;
    return weekday;
}

void print_time_diff(clock_t start, const char *message) {
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s in %f seconds\n", message, cpu_time_used);
}

