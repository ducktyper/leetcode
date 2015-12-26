/*
 * SOURCE: https://leetcode.com/problems/integer-to-roman
 */
char* intToRoman(int num) {
    int  integers[] = {1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1};
    char * romans[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char * out = malloc(sizeof(char) * 16);
    int i = 0, j = 0;
    while (num)
    {
        while (num < integers[j]) j++;
        int z = 0;
        while (romans[j][z]) out[i++] = romans[j][z++];
        num -= integers[j];
    }
    out[i] = '\0';
    return out;
}
