#include "helper.h"
#include "leetcode_009_palindrome_number.c"

int main()
{
    assertInt(1, isPalindrome(1));
    assertInt(1, isPalindrome(121));
    assertInt(1, isPalindrome(1221));
    assertInt(0, isPalindrome(12231));
    assertInt(1, isPalindrome(1410110141));
    assertInt(0, isPalindrome(-1));
}
