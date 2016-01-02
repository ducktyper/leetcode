#include <stdbool.h>

/*
 * SOURCE: https://leetcode.com/problems/valid-parentheses
 */
bool isValid(char* s) {
    int size = strlen(s);
    char active[size];
    int p = 0;

    for (int i = 0; i < size; i++)
    {
        if      (s[i] == '(') active[p++] = ')';
        else if (s[i] == '[') active[p++] = ']';
        else if (s[i] == '{') active[p++] = '}';
        else if (--p < 0 || s[i] != active[p]) return 0;
    }

    return !p;
}
