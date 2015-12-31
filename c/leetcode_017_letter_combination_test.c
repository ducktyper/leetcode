#include "helper.h"
#include "leetcode_017_letter_combination.c"

int assertLetterCombination(char * expected, char * digit);

int main()
{
    assert(assertLetterCombination("[ad,ae,af,bd,be,bf,cd,ce,cf]", "23"));
    assert(assertLetterCombination("[p,q,r,s]", "7"));
    assert(assertLetterCombination("[t,u,v]", "8"));
    assert(assertLetterCombination("[w,x,y,z]", "9"));
    assert(assertLetterCombination("[ww,wx,wy,wz,xw,xx,xy,xz,yw,yx,yy,yz,zw,zx,zy,zz]", "99"));
}

int assertLetterCombination(char * expected, char * digit)
{
    int returnSize;
    char ** out = letterCombinations(digit, &returnSize);
    char * actual = stringArrayToString(out, returnSize);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;
    free(actual);
    freeStringArray(out, returnSize);
    return status;
}
