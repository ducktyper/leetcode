#include "helper.h"
#include "leetcode_025_reverse_k_group.c"

int assertReverseKGroup(char * expected, char * input, int k);

int main()
{
    assert(assertReverseKGroup("[2,1]", "[1,2]", 2));
    assert(assertReverseKGroup("[2,1,4,3]", "[1,2,3,4]", 2));
    assert(assertReverseKGroup("[3,2,1,6,5,4]", "[1,2,3,4,5,6]", 3));
}

int assertReverseKGroup(char * expected, char * input, int k)
{
    struct ListNode * node = stringToListNode(input);
    struct ListNode * out = reverseKGroup(node, k);
    char * actual = listNodeToString(out);
    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    free(actual);
    freeListNode(out);

    return status;
}
