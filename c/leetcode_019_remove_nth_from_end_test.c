#include "helper.h"
#include "leetcode_019_remove_nth_from_end.c"

int assertRemoveNthFromEnd(char * expected, char * arrayString, int n);

int main()
{
    assert(assertRemoveNthFromEnd("[]", "[1]", 1));
    assert(assertRemoveNthFromEnd("[1,2,3,5]", "[1,2,3,4,5]", 2));
}

int assertRemoveNthFromEnd(char * expected, char * arrayString, int n)
{
    struct ListNode * node = stringToListNode(arrayString);
    struct ListNode * out = removeNthFromEnd(node, n);
    char * actual = listNodeToString(out);

    int status = 1;
    if (!assertString(expected, actual)) status = 0;

    free(actual);
    freeListNode(out);

    return status;
}
