#include "helper.h"
#include "leetcode_022_generate_parenthesis.c"

int assertGenerateParenthesis(char * expected, int n);

int main()
{
    assert(assertGenerateParenthesis("[()]", 1));
    assert(assertGenerateParenthesis("[(()),()()]", 2));
    assert(assertGenerateParenthesis("[((())),(()()),(())(),()(()),()()()]", 3));
}

int assertGenerateParenthesis(char * expected, int n)
{
    int count = countArrayInString(expected);
    int returnSize;
    char** out = generateParenthesis(n, &returnSize);
    char * actual = stringArrayToString(out, returnSize);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;
    if (!assertInt(count, returnSize)) status = 0;

    freeStringArray(out, returnSize);
    free(actual);

    return status;
}

