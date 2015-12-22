/**
 * SOURCE: https://leetcode.com/problems/string-to-integer-atoi
 */
int myAtoi(char* str) {
    long out = 0;
    int minus = 0;

    while (*str == ' ') str++;

    if (*str == '-' || *str == '+') minus = (*(str++) == '-');

    while (*str)
    {
        if (*str < '0' || *str > '9') break;

        if (out) out *= 10;
        if (minus)
        {
            out -= *str - '0';
            if (out < INT_MIN) return INT_MIN;
        }
        else
        {
            out += *str - '0';
            if (out > INT_MAX) return INT_MAX;
        }
        str++;
    }

    return out;
}
