#include "helper.h"
#include "leetcode_005_longest_palindromic_substring.c"

int main()
{
    assertString("aba", longestPalindrome("aba"));
    assertString("aba", longestPalindrome("caba"));
    assertString("cabac", longestPalindrome("cabac"));
    assertString("abcba", longestPalindrome("aabcbae"));
    assertString("bb", longestPalindrome("bb"));
    assertString("ccc", longestPalindrome("ccc"));
    assertString("aaaa", longestPalindrome("aaaa"));
    assertString("a", longestPalindrome("a"));
    assertString("a", longestPalindrome("ab"));
}
