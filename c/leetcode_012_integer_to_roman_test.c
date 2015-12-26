#include "helper.h"
#include "leetcode_012_integer_to_roman.c"

int assertIntToRoman(char * roman, int num);

int main()
{
    assert(assertIntToRoman("I", 1));
    assert(assertIntToRoman("II", 2));
    assert(assertIntToRoman("V", 5));
    assert(assertIntToRoman("IV", 4));
    assert(assertIntToRoman("VI", 6));
    assert(assertIntToRoman("X", 10));
    assert(assertIntToRoman("IX", 9));
    assert(assertIntToRoman("M", 1000));
    assert(assertIntToRoman("MMMCMXCIX", 3999));
}

int assertIntToRoman(char * roman, int num)
{
    char * actual = intToRoman(num);
    int status = 1;
    if (!assertString(roman, actual)) status = 0;
    free(actual);
    return status;
}
