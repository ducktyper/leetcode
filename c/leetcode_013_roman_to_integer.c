/*
 * SOURCE: https://leetcode.com/problems/roman-to-integer
 */
int romanToInt(char* s) {
    int  integers[] = {1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1};
    char * romans[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int out = 0, i = 0;
    while (*s)
    {
        while (romans[i][0] != s[0] || (romans[i][1] && romans[i][1] != s[1])) i++;
        out += integers[i];
        s += strlen(romans[i]);
    }
    return out;
}
