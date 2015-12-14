#include "helper.h"
#include "leetcode_003_longest_substring.c"

int main()
{
    assertInt(3, lengthOfLongestSubstring("abca"));
    assertInt(5, lengthOfLongestSubstring("abcabcdea"));
    assertInt(3, lengthOfLongestSubstring("dvdf"));
    assertInt(2, lengthOfLongestSubstring("cdd"));
    assertInt(2, lengthOfLongestSubstring("abba"));
    assertInt(3, lengthOfLongestSubstring("ohomm"));
}
