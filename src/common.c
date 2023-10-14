#include "uni.h"

const char *scode_str[] = {
    [S_OK]              = "Success",
    [S_FAIL]            = "Fail",
    [S_UNKNOWN]         = "Unknown"
};

const char* get_scode_str(SCODE status) {
    return scode_str[status];
}
