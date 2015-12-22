#include "helper.h"
#include  "leetcode_007_string_to_integer.c"

int main()
{
    assertInt(12, myAtoi("12"));
    assertInt(-12, myAtoi("-12"));
    assertInt(12, myAtoi("+12"));
    assertInt(0, myAtoi("+-12"));
    assertInt(0, myAtoi("0"));
    assertInt(10, myAtoi("    010"));
    assertInt(4500, myAtoi("     +004500"));
    assertInt(-12, myAtoi("  -0012a42"));
    assertInt(0, myAtoi("   +0 123"));
    assertInt(1234567, myAtoi("1234567"));
    assertInt(-2147483648, myAtoi("-2147483648"));
    assertInt(2147483647, myAtoi("9223372036854775809"));
}
