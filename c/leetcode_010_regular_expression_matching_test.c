#include "helper.h"
#include "leetcode_010_regular_expression_matching.c"

int main()
{
    assertInt(1, isMatch("",""));
    assertInt(1, isMatch("a","a"));
    assertInt(1, isMatch("ab","ab"));
    assertInt(1, isMatch("azb","a.b"));
    assertInt(0, isMatch("azb","a."));
    assertInt(1, isMatch("aa","a*"));
    assertInt(1, isMatch("aab","a*b"));
    assertInt(1, isMatch("aaab","a*b"));
    assertInt(0, isMatch("aacb","a*b"));
    assertInt(1, isMatch("aab",".*b"));
    assertInt(1, isMatch("acb",".*b"));
    assertInt(1, isMatch("b","a*b"));
    assertInt(1, isMatch("bbbba",".*a*a"));
    assertInt(0, isMatch("bbab","b*a*"));
    assertInt(0, isMatch("","..*"));
    assertInt(1, isMatch("a","ab*"));
    assertInt(1, isMatch("","c*c*"));
}
