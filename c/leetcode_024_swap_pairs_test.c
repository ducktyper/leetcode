#include "helper.h"
#include "leetcode_024_swap_pairs.c"

int assertSwapPairs(char * expected, char * input);

int main()
{
    assert(assertSwapPairs("[]", "[]"));
    assert(assertSwapPairs("[1]", "[1]"));
    assert(assertSwapPairs("[2,1,4,3]", "[1,2,3,4]"));
}

int assertSwapPairs(char * expected, char * input)
{
    struct ListNode * node = stringToListNode(input);
    struct ListNode * out = swapPairs(node);
    char * actual = listNodeToString(out);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    free(actual);
    freeListNode(out);

    return status;
}
