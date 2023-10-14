#ifndef __COMMON_H__
#define __COMMON_H__

/* Definition */
#define CLEAR                   "\033[m"
#define RED                     "\033[0;32;31m"
#define LIGHT_RED               "\033[1;31m"
#define GREEN                   "\033[0;32;32m"
#define LIGHT_GREEN             "\033[1;32m"
#define BLUE                    "\033[0;32;34m"
#define LIGHT_BLUE              "\033[1;34m"
#define DARY_GRAY               "\033[1;30m"
#define CYAN                    "\033[0;36m"
#define LIGHT_CYAN              "\033[1;36m"
#define PURPLE                  "\033[0;35m"
#define LIGHT_PURPLE            "\033[1;35m"
#define BROWN                   "\033[0;33m"
#define YELLOW                  "\033[1;33m"
#define LIGHT_GRAY              "\033[0;37m"
#define WHITE                   "\033[1;37m"

#define TRACE()                 printf(CYAN"[TRACE][%s][%s:%d]\n"CLEAR, __FILE__, __func__, __LINE__)
#define ERROR(fmt, args...)     printf(RED"[ERROR][%s:%d] "fmt""CLEAR, __func__, __LINE__, ##args)
#define WARN(fmt, args...)      printf(YELLOW"[WARNING][%s:%d] "fmt""CLEAR, __func__, __LINE__, ##args)
#define INFO(fmt, args...)      printf(GREEN"[INFO][%s:%d] "fmt""CLEAR, __func__, __LINE__, ##args)
#define DEBUG(fmt, args...)     printf(BLUE"[DEBUG][%s:%d] "fmt""CLEAR, __func__, __LINE__, ##args)
#define INIT(fmt, args...)      printf(LIGHT_GREEN"[INIT][%s:%d] "fmt""CLEAR, __func__, __LINE__, ##args)

#define RETURN_SOK_IF(expr)     if (expr)   return S_OK;
#define RETURN_SOK_IF_NOT(expr) if (!expr)  return S_OK;

#define RETURN_SFAIL_IF_NULL(expr) \
    if (expr == NULL){ \
        ERROR("NULL detected!(%s)\n", __FILE__); \
        return S_FAIL;  \
    }

#define RETURN_SFAIL_IF(expr) \
    if (expr){ \
        ERROR("expr failed!(%s)\n", __FILE__); \
        return S_FAIL;  \
    }

#define RETURN_SFAIL_IF_NOT(expr) \
    if (!(expr)){ \
        ERROR("exer failed!(%s)\n", __FILE__); \
        return S_FAIL;  \
    }

#define CHECK_STATUS(scode, success_expr /* S_OK */, fail_expr /* S_FAIL */) \
    { \
        SCODE status_expr; \
        if (scode == S_OK){ \
            status_expr = success_expr; \
            INFO("Status OK!(expr: %s)\n", get_scode_str(status_expr)); \
        } else { \
            status_expr = fail_expr; \
            ERROR("Status failed!(expr: %s)\n", get_scode_str(status_expr)); \
        } \
    }

/* Enum and Structure */
typedef enum {
    S_OK                = 0,
    S_FAIL              = 1,
    S_UNKNOWN           = 2
} SCODE;


/* Functions */
const char* get_scode_str(SCODE status);

#endif // __COMMON_H__
