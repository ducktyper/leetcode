#include "helper.h"
#include "leetcode_007_reverse.c"

int main()
{
    assertInt(0, reverse(-2147483648));
    assertInt(-463847412, reverse(-214748364));
    assertInt(463847412, reverse(214748364));
    assertInt(-321, reverse(-123));
    assertInt(21, reverse(12));
}
