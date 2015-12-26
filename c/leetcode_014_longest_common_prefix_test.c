#include "helper.h"
#include "leetcode_014_longest_common_prefix.c"
#include <stdarg.h>

int assertLongetstComonPrefix(char * expected, int count, ...);

int main()
{
    assert(assertLongetstComonPrefix("", 0));
    assert(assertLongetstComonPrefix("ab", 2, "abd", "abc"));
}

int assertLongetstComonPrefix(char * expected, int count, ...)
{
    va_list arguments;
    va_start(arguments, count);

    int status = 1;
    char * strings[count];
    for (int i = 0; i < count; ++i )
    {
        strings[i] = va_arg(arguments, char *);
    }
    char * actual = longestCommonPrefix(strings, count);
    if (!assertString(expected, actual)) status = 0;
    free(actual);

    va_end(arguments);
    return status;
}
