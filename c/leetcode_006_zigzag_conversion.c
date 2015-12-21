/**
 * SOURCE: https://leetcode.com/problems/zigzag-conversion
 *
 *  0   6    12 | 6
 *  1 5 7 11 13 | 4,2
 *  2 4 8 10 14 | 2,4
 *  3   9    15 | 6
 *
 *  0    8    16 | 8
 *  1 7  9 15 17 | 6,2
 *  2 6 10 14 18 | 4,4
 *  3 5 11 13 19 | 2,6
 *  4   12    20 | 8
 *
 *  0   10    20 | 10
 *  1 9 11 19 21 | 8,2
 *  2 8 12 18 22 | 6,4
 *  3 7 13 17 23 | 4,6
 *  4 6 14 16 24 | 2,8
 *  5   15    25 | 10
 */
char* convert(char* s, int numRows) {
    int length = strlen(s), i = 0, step = (numRows - 1) * 2;
    if (!step) step = 1;
    char * out = malloc(sizeof(char) * (length + 1));
    for (int j = 0; j < numRows; j++)
    {
        int k = j, diff = j * 2;
        while (k < length)
        {
            out[i++] = s[k];
            diff = (step == diff ? step : step - diff);
            k += diff;
        }
    }

    out[length] = '\0' ;
    return out;
}
