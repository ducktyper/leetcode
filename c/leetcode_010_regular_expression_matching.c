#include <stdbool.h>

/*
 * SOURCE: https://leetcode.com/problems/regular-expression-matching
 */
bool isMatch(char* s, char* p) {
    if (!*s && !*p) return true;
    if (*p && p[1] == '*')
    {
        if (isMatch(s, &p[2])) return true;
        while (*s)
        {
            if (!(*s == *p || *p == '.')) break;
            if (isMatch(&s[1], &p[2])) return true;
            s++;
        }
    }
    if (*s && (*s == *p || *p == '.')) return isMatch(&s[1], &p[1]);
    return false;
}
