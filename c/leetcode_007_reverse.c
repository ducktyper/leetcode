/*
 * SOURCE: https://leetcode.com/problems/reverse-integer
 */
int reverse(int x) {
    int out = 0;
    while (x)
    {
        long newOut = (long)out * 10 + x % 10;
        if ((out = newOut) != newOut) return 0;
        x /= 10;
    }
    return out;
}
