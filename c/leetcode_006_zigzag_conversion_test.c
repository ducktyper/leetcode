#include "helper.h"
#include "leetcode_006_zigzag_conversion.c"

int main()
{
    assertString("PAHNAPLSIIGYIR", convert("PAYPALISHIRING", 3));
    assertString("acbbdcad", convert("abcdabcd", 4));
    assertString("A", convert("A", 1));
}
