#include <stdbool.h>

/*
 * SOURCE: https://leetcode.com/problems/palindrome-number
 */
bool isPalindrome(int x) {
    if (x < 0) return false;
    int y = 0, i = x;
    while (i)
    {
        y = y * 10 + i % 10;
        i /= 10;
    }
    return x == y;
}
