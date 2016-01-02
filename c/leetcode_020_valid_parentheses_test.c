#include "helper.h"
#include "leetcode_020_valid_parentheses.c"

int main()
{
    assertInt(1, isValid("()"));
    assertInt(1, isValid("({})"));
    assertInt(1, isValid("({[]})"));
    assertInt(1, isValid("({[]})()"));
    assertInt(0, isValid("([]})"));
    assertInt(0, isValid("(a)"));
}
