#include "helper.h"
#include "leetcode_013_roman_to_integer.c"

int main()
{
    assertInt(1, romanToInt("I"));
    assertInt(2, romanToInt("II"));
    assertInt(5, romanToInt("V"));
    assertInt(4, romanToInt("IV"));
    assertInt(6, romanToInt("VI"));
    assertInt(10, romanToInt("X"));
    assertInt(9, romanToInt("IX"));
    assertInt(1000, romanToInt("M"));
    assertInt(3999, romanToInt("MMMCMXCIX"));
}
