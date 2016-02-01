#include "helper.h"
#include "leetcode_028_str_str.c"

int main()
{
    assertInt(0, strStr("abc", ""));
    assertInt(0, strStr("a", "a"));
    assertInt(0, strStr("aaa", "a"));
    assertInt(0, strStr("aaa", "aa"));
    assertInt(0, strStr("abc", "abc"));
    assertInt(0, strStr("abc", "ab"));
    assertInt(1, strStr("abc", "bc"));
    assertInt(1, strStr("abcbd", "bc"));
    assertInt(3, strStr("abdbc", "bc"));
    assertInt(1, strStr("abcbc", "bcbc"));
    assertInt(2, strStr("abbc", "bc"));
    assertInt(-1, strStr("aaa", "aaaa"));
    assertInt(4, strStr("mississippi", "issip"));
    assertInt(-1, strStr("mississippi", "mississippii"));
}
